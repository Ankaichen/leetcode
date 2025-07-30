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

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "../../utils/compare.hpp"
#include "../../utils/delete.hpp"
#include "../../utils/parse.hpp"
#include "./test_case_reader.hpp"
#include "forward_declaration.h"

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
 * Task template base class
 * @tparam ID   the task number
 * @tparam Res  the task function return type
 * @tparam Args the task function parameter type pack
 */
template <const char *Name, typename Res, typename... Args>
class Task<Name, Res(Args...)> {
public:
    using BaseType = Task<Name, Res(Args...)>;

    Task() = default;

    Task(const BaseType &problem) = delete;

    Task(BaseType &&problem) = delete;

    void init() { this->_testCaseReader.setFile("./task_input" + this->getTestCaseFileName()); }

    virtual ~Task() noexcept = 0;

    /**
     * Get the task title
     * @return the task title
     */
    [[nodiscard]] inline std::string title() const { return std::string{Name}; };

    [[nodiscard]] virtual std::string getTestCaseFileName() const;

#define INIT_TESTCASE_FILE_NAME                                                    \
    [[nodiscard]] std::string getTestCaseFileName() const override {               \
        std::string fileName{__FILE_NAME__};                                       \
        std::string fileNameClean{fileName.substr(0, fileName.find_last_of('.'))}; \
        return fileNameClean + ".txt";                                             \
    }

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
    TestCaseReader<Res(Args...)> _testCaseReader;
};

template <const char *Name, typename Res, typename... Args>
Task<Name, Res(Args...)>::~Task() noexcept = default;

template <const char *Name, typename Res, typename... Args>
inline std::vector<TestResult> Task<Name, Res(Args...)>::test() const {
    std::vector<TestResult> testResult{};
    this->_testCaseReader.forEachTestCase([this](Res res, Args... args) -> void {
        Res solveResult{};
        try {
            solveResult = this->solve(args...);
        } catch (const std::exception &e) {
            std::ostringstream oss;
            ((oss << Parse::toString<Args>(args) << "; "), ...);
            std::cerr << "An error occurred in the test case:" << std::endl << "\t" << oss.str() << std::endl << "\t" << e.what() << std::endl;
            exit(-1);
        }



        
    });

    std::vector<TestResult> testResult(this->_testCase.size());
    unsigned int index = 0;
    std::for_each(this->_testCase.cbegin(), this->_testCase.cend(), [this, &testResult, index](const TestCase &testCase) mutable -> void {
        Res resValue{};
        try {
            resValue = this->parseArgsAndSolve(testCase.input);
        } catch (const std::exception &e) {
            std::cerr << "An error occurred in the test case:" << std::endl << "\t" << testCase.input << std::endl << "\t" << e.what() << std::endl;
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

#endif  // LEETCODE_TASK_HPP
