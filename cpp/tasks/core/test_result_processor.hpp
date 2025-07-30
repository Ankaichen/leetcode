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

template<typename InputRes, typename OutputRes>
class TestResultProcessor {
protected:
    using CleanInputType = std::remove_cvref_t<InputRes>;
    using CleanOutputType = std::remove_cvref_t<OutputRes>;
public:
    TestResultProcessor() = default;

    virtual ~TestResultProcessor() noexcept = 0;

    virtual CleanOutputType processResult(const CleanInputType &input) const = 0;
};

template<typename InputRes, typename OutputResult>
TestResultProcessor<InputRes, OutputResult>::~TestResultProcessor() noexcept = default;

template<typename InputRes>
class NormalTestResultProcessor : public TestResultProcessor<InputRes, InputRes> {
    using CleanInputType = TestResultProcessor<InputRes, InputRes>::CleanInputType;
    using CleanOutputType = TestResultProcessor<InputRes, InputRes>::CleanOutputType;
public:
    NormalTestResultProcessor() = default;

    ~NormalTestResultProcessor() noexcept override = default;

    CleanOutputType processResult(const CleanInputType &input) const override;
};

template<typename InputRes>
NormalTestResultProcessor<InputRes>::CleanOutputType
NormalTestResultProcessor<InputRes>::processResult(const CleanInputType &input) const {
    return input;
}



#endif  // LEETCODE_TEST_RESULT_PROCESSOR_HPP
