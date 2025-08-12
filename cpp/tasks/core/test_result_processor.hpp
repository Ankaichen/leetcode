/**
 ******************************************************************************
 * @file           : test_result_processor.hpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-7-28
 ******************************************************************************
 */

#ifndef LEETCODE_TEST_RESULT_PROCESSOR_HPP
#define LEETCODE_TEST_RESULT_PROCESSOR_HPP

#include <type_traits>

#include "./task_type_traits.hpp"
#include "./utils.h"

template<typename InputRes, typename OutputRes>
class TestResultProcessor {
protected:
    using CleanInputType = TypeTraits::clean_type_t<InputRes>;
    using CleanOutputType = TypeTraits::clean_type_t<OutputRes>;

public:
    TestResultProcessor() = default;

    virtual ~TestResultProcessor() noexcept = 0;

    [[nodiscard]] virtual CleanOutputType processResult(const CleanInputType &input) const = 0;
};

template<typename InputRes, typename OutputResult>
TestResultProcessor<InputRes, OutputResult>::~TestResultProcessor() noexcept = default;

template<typename InputRes>
class NormalTestResultProcessor : public TestResultProcessor<InputRes, InputRes> {
    using typename TestResultProcessor<InputRes, InputRes>::CleanInputType;
    using typename TestResultProcessor<InputRes, InputRes>::CleanOutputType;

public:
    NormalTestResultProcessor() = default;

    ~NormalTestResultProcessor() noexcept override = default;

    [[nodiscard]] CleanOutputType processResult(const CleanInputType &input) const override;
};

template<typename InputRes>
NormalTestResultProcessor<InputRes>::CleanOutputType NormalTestResultProcessor<InputRes>::processResult(const CleanInputType &input) const {
    return input;
}

class ListNodeTestResultProcessor : public TestResultProcessor<ListNode *, ListNode *> {
public:
    using typename TestResultProcessor<ListNode *, ListNode *>::CleanInputType;
    using typename TestResultProcessor<ListNode *, ListNode *>::CleanOutputType;

public:
    ListNodeTestResultProcessor() = default;

    ~ListNodeTestResultProcessor() noexcept override = default;

    [[nodiscard]] CleanOutputType processResult(const CleanInputType &input) const override;
};

template<TypeTraits::is_container_c InputRes, int Depth>
class UnorderedTestResultProcessor : public TestResultProcessor<InputRes, InputRes> {
    using typename TestResultProcessor<InputRes, InputRes>::CleanInputType;
    using typename TestResultProcessor<InputRes, InputRes>::CleanOutputType;

public:
    UnorderedTestResultProcessor() = default;

    ~UnorderedTestResultProcessor() noexcept override = default;

    [[nodiscard]] CleanOutputType processResult(const CleanInputType &input) const override;

private:
    template<typename T>
    [[nodiscard]] inline std::remove_cvref_t<T> processItem(const T &input, int cur_depth = 0) const;
};

template<TypeTraits::is_container_c InputRes, int Depth>
UnorderedTestResultProcessor<InputRes, Depth>::CleanOutputType UnorderedTestResultProcessor<InputRes, Depth>::processResult(
    const UnorderedTestResultProcessor::CleanInputType &input) const {
    return this->processItem(input);
}

template<TypeTraits::is_container_c InputRes, int Depth>
template<typename T>
std::remove_cvref_t<T> UnorderedTestResultProcessor<InputRes, Depth>::processItem(const T &input, int cur_depth) const {
    if constexpr (TypeTraits::is_vector_v<T>) {
        if (Depth < 0 || cur_depth < Depth) {
            std::multiset<TypeTraits::vector_value_t<T>> resSet{};
            for (auto v : input) {
                resSet.insert(this->processItem(v, cur_depth + 1));
            }
            return std::vector<TypeTraits::vector_value_t<T>>{resSet.begin(), resSet.end()};
        } else {
            return input;
        }
    } else {
        return input;
    }
}

class ACMTestResultProcessor : public TestResultProcessor<std::ostringstream &, std::ostringstream &> {
    using typename TestResultProcessor<std::ostringstream &, std::ostringstream &>::CleanInputType;
    using typename TestResultProcessor<std::ostringstream &, std::ostringstream &>::CleanOutputType;

public:
    ACMTestResultProcessor() = default;

    ~ACMTestResultProcessor() noexcept override = default;

    [[nodiscard]] CleanOutputType processResult(CleanInputType &input) const override;
};

#endif  // LEETCODE_TEST_RESULT_PROCESSOR_HPP
