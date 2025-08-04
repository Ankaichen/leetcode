/**
 ******************************************************************************
 * @file           : task.hpp
 * @author         : An Kaichen
 * @brief          : The template base class of task
 * @date           : 25-4-18
 ******************************************************************************
 */

#ifndef LEETCODE_TASK_HPP
#define LEETCODE_TASK_HPP

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "../../utils/compare.hpp"
#include "../../utils/delete.hpp"
#include "../../utils/parse.hpp"
#include "./test_case_reader.hpp"
#include "./test_result_processor.hpp"
#include "./utils.h"

/**
 * Test result
 * flag:   whether the result is true
 * output: the output result
 */
struct TestResult {
    bool flag{};
    std::string output;
    std::chrono::nanoseconds spendTime{};
};

template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Func>
class Task;

/**
 * Task template base class
 * @tparam ID   the task number
 * @tparam Res  the task function return type
 * @tparam Args the task function parameter type pack
 */
template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Res, typename... Args>
class Task<Name, Reader, Processor, Res(Args...)> {
    static_assert(TypeTraits::is_task_fit_c<Task<Name, Reader, Processor, Res(Args...)>, Reader, Processor>);

    template<TypeTraits::is_task_c T>
    friend class TaskRunner;

public:
    Task() = default;

    Task(const Task<Name, Reader, Processor, Res(Args...)> &problem) = delete;

    Task(Task<Name, Reader, Processor, Res(Args...)> &&problem) = delete;

    virtual ~Task() noexcept = 0;

    /**
     * Get the task title
     * @return the task title
     */
    [[nodiscard]] inline std::string title() const { return std::string{Name}; };

    [[nodiscard]] virtual std::string getTestCaseFileName() const = 0;

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
    [[nodiscard]] virtual Res solve(Args... args) const = 0;

private:
    [[nodiscard]] std::string getTestCaseFilePath() const { return "./task_input/" + this->getTestCaseFileName(); }

private:
    mutable Reader _testCaseReader;
    Processor _testResultProcessor;
};

template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Res, typename... Args>
Task<Name, Reader, Processor, Res(Args...)>::~Task() noexcept = default;

template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Res, typename... Args>
inline std::vector<TestResult> Task<Name, Reader, Processor, Res(Args...)>::test() const {
    this->_testCaseReader.setFile(this->getTestCaseFilePath());
    using ProcessedResultType = decltype(this->_testResultProcessor.processResult(std::declval<Res>()));
    std::vector<TestResult> testResult{};
    this->_testCaseReader.forEachTestCase(
        [this, &testResult](Res res, Args... args) -> void {
            // Res solveResult{};
            std::chrono::nanoseconds spendTime{};
            // try {
            auto startTime = std::chrono::high_resolution_clock::now();
            Res solveResult = this->solve(args...);
            spendTime = std::chrono::high_resolution_clock::now() - startTime;
            // } catch (const std::exception &e) {
            // std::ostringstream oss;
            // ((oss << Parse::toString<Args>(args) << "; "), ...);
            // std::cerr << "An error occurred in the test case:" << std::endl << "\t" << oss.str() << std::endl << "\t" << e.what() << std::endl;
            // exit(-1);
            // }
            std::string solveResultString = Parse::toString<Res>(solveResult);
            ProcessedResultType processedSolveResult = this->_testResultProcessor.processResult(solveResult);
            ProcessedResultType processedResult = this->_testResultProcessor.processResult(res);
            bool resultFlag = Compare::compare(processedSolveResult, processedResult);
            if (std::chrono::duration_cast<std::chrono::milliseconds>(spendTime).count() > 0) resultFlag = false;
            testResult.emplace_back(resultFlag, solveResultString, spendTime);
            Delete::deleteValue(solveResult);
            Delete::deleteValue(res);
            Delete::deleteValue(processedSolveResult);
            Delete::deleteValue(processedResult);
        },
        nullptr);
    return testResult;
}

#endif  // LEETCODE_TASK_HPP
