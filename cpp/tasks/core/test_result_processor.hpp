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

template <typename InputRes, typename OutputResult>
class TestResultProcessor {
public:
    TestResultProcessor() = default;
    virtual ~TestResultProcessor() noexcept = 0;

    virtual OutputResult processResult(InputRes input) const = 0;
};

template <typename InputRes, typename OutputResult>
TestResultProcessor<InputRes, OutputResult>::~TestResultProcessor() noexcept = default;

template <typename InputRes, typename OutputResult>
class NormalTestResultProcessor {
public:
    NormalTestResultProcessor() = default;
    ~NormalTestResultProcessor() noexcept override = default;

    OutputResult processResult(InputRes input) const override;
};

#endif  // LEETCODE_TEST_RESULT_PROCESSOR_HPP
