/**
  ******************************************************************************
  * @file           : test_case_reader.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-7-28
  ******************************************************************************
  */

#ifndef LEETCODE_TEST_CASE_READER_HPP
#define LEETCODE_TEST_CASE_READER_HPP

#include <functional>
#include <fstream>
#include <ios>

#include "./forward_declaration.h"

template<typename Res, typename... Args>
class TestCaseReader<Res(Args...)> {
public:
    using TestCaseCallBack = std::function<void(Res, Args...)>;
public:
    TestCaseReader(std::string_view filePath) : _fileStream{std::string{filePath}, std::ios::out} {}

    virtual ~TestCaseReader() noexcept {}

    void forEachTestCase(TestCaseCallBack callback) const;

    virtual bool getNextTestCase(TestCaseCallBack callback) const = 0;

protected:
    std::fstream _fileStream{};
};

template<typename Res, typename... Args>
void TestCaseReader<Res(Args...)>::forEachTestCase(std::function<void(Res, Args...)> callback) const {
    while (getNextTestCase(callback));
}

template<typename Res, typename... Args>
class LeetCodeTestCaseReader<Res(Args...)> : public TestCaseReader<Res(Args...)> {
public:
    LeetCodeTestCaseReader(std::string_view filePath);

    ~LeetCodeTestCaseReader() noexcept override;

    bool getNextTestCase(typename TestCaseReader<Res(Args...)>::TestCaseCallBack callback) const override;

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
};

template<typename Res, typename... Args>
LeetCodeTestCaseReader<Res(Args...)>::LeetCodeTestCaseReader(std::string_view filePath)
        :TestCaseReader<Res(Args...)>{filePath} {}

template<typename Res, typename... Args>
LeetCodeTestCaseReader<Res(Args...)>::~LeetCodeTestCaseReader() noexcept {}

template<typename Res, typename... Args>
bool LeetCodeTestCaseReader<Res(Args...)>::getNextTestCase(
        typename TestCaseReader<Res(Args...)>::TestCaseCallBack callback) const {
    std::string line{};
    while (std::getline(this->_fileStream, line)) {
        this->parseArgsAndSolve(line);
    }


    return true;
}

#endif //LEETCODE_TEST_CASE_READER_HPP
