/**
  ******************************************************************************
  * @file           : task.h
  * @author         : An Kaichen
  * @brief          : The template base class of task
  * @date           : 25-4-18
  ******************************************************************************
  */

#ifndef LEETCODE_TASK_HPP
#define LEETCODE_TASK_HPP

#include <string>
#include <vector>
#include <functional>
#include <iostream>

#include "../utils/parse.hpp"
#include "../utils/compare.hpp"
#include "../utils/delete.hpp"
#include "forward_declaration.h"

/**
 * Test case
 * input:    the test input value, using ";" to split parameters,
 *           example: "input1 = [1, 2, 3, 4]; input2 = 3"
 * expected: the expected output value
 *           example: "[1, 2, 3]"
 */
struct TestCase {
    std::string input;
    std::string expected;
};

/**
 * Test result
 * flag:   whether the result is true
 * output: the output result
 */
struct TestResult {
    bool flag{};
    std::string output;
};

/**
 * Task template class
 * @tparam ID   the task number
 * @tparam Func the task function type
 */
template<unsigned int ID, typename Func>
class Task;

/**
 * Task template base class
 * @tparam ID   the task number
 * @tparam Res  the task function return type
 * @tparam Args the task function parameter type pack
 */
template<unsigned int ID, typename Res, typename... Args>
class Task<ID, Res(Args...)> {

public:
    using BaseType = Task<ID, Res(Args...)>;

    Task() = default;

    Task(const Task<ID, Res(Args...)> &problem) = delete;

    Task(Task<ID, Res(Args...)> &&problem) = delete;

    virtual ~Task() noexcept = 0;

    /**
     * Get the task title
     * @return the task title
     */
    [[nodiscard]] virtual inline std::string title() const = 0;

    /**
     * Add a test case
     * @param testCaseInput    the input of test case
     * @param testCaseExpected the expected of test case
     */
    inline void addTestCase(std::string_view testCaseInput, std::string_view testCaseExpected);

    [[nodiscard]] inline const std::vector<TestCase> &getTestCase() const { return this->_testCase; }

    /**
     * Use the solve() function to process the test case and return a bool vector,
     * to indicate whether each test case passes
     * @return bool vector
     */
    [[nodiscard]] inline std::vector<TestResult> test() const;

    /**
     * Location of algorithm implementation, override by derived class
     * @param args parameters
     * @return algorithm result
     */
    virtual Res solve(Args... args) const = 0;

private:
    /**
     * Auxiliary function for parsing strings based on parameter positions, then run the solve function
     * @tparam IS   parameter index
     * @param input test case input string
     * @return algorithm result
     */
    template<std::size_t... IS>
    Res parseArgsAndSolveHelper(const std::string &input, std::index_sequence<IS...>) const;

    /**
     * Auxiliary function, runs the solve function based on the test case string input
     * @param input test case input string
     * @return algorithm result
     */
    Res parseArgsAndSolve(const std::string &input) const;

public:
    static constexpr unsigned int id{ID};
private:
    std::vector<TestCase> _testCase{};
};

template<unsigned int ID, typename Res, typename... Args>
Task<ID, Res(Args...)>::~Task() noexcept = default;

template<unsigned int ID, typename Res, typename... Args>
inline void Task<ID, Res(Args...)>::addTestCase(std::string_view testCaseInput, std::string_view testCaseExpected) {
    this->_testCase.emplace_back(
            std::string{testCaseInput},
            std::string{testCaseExpected}
    );
}

template<unsigned int ID, typename Res, typename... Args>
inline std::vector<TestResult> Task<ID, Res(Args...)>::test() const {
    std::vector<TestResult> testResult(this->_testCase.size());
    unsigned int index = 0;
    std::for_each(
            this->_testCase.cbegin(), this->_testCase.cend(),
            [this, &testResult, index](const TestCase &testCase) mutable -> void {
                Res resValue{};
                try {
                    resValue = this->parseArgsAndSolve(testCase.input);
                } catch (const std::exception &e) {
                    std::cerr << "An error occurred in the test case:" << std::endl
                              << "\t" << testCase.input << std::endl
                              << "\t" << e.what() << std::endl;
                    exit(-1);
                }
                Res expectedValue = Parse::parseType<Res>(testCase.expected);
                bool resultFlag = Compare::compare(resValue, expectedValue);
                unsigned int curI = index++;
                testResult[curI].flag = resultFlag;
                testResult[curI].output = Parse::toString<Res>(resValue);
                Delete::deleteValue(resValue);
                Delete::deleteValue(expectedValue);
            });
    return testResult;
}

template<unsigned int ID, typename Res, typename... Args>
template<std::size_t... IS>
Res Task<ID, Res(Args...)>::parseArgsAndSolveHelper(const std::string &input, std::index_sequence<IS...>) const {
    return this->solve(Parse::parseTypeByIndex<IS, Args>(input)...);
}

template<unsigned int ID, typename Res, typename... Args>
Res Task<ID, Res(Args...)>::parseArgsAndSolve(const std::string &input) const {
    return this->parseArgsAndSolveHelper(input, std::index_sequence_for<Args...>{});
}


#endif //LEETCODE_TASK_HPP
