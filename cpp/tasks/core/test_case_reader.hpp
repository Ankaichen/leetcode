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

#include <fstream>
#include <functional>
#include <ios>
#include <string>

#include "../../utils/parse.hpp"
#include "./forward_declaration.h"

template <typename Res, typename... Args>
class TestCaseReader<Res(Args...)> {
public:
    using TestCaseCallBack = std::function<void(Res, Args...)>;

public:
    TestCaseReader() = default;

    explicit TestCaseReader(std::string_view filePath) : _fileStream{std::string{filePath}, std::ios::out} {}

    virtual ~TestCaseReader() noexcept = 0;

    void setFile(std::string_view filePath);

    void forEachTestCase(TestCaseCallBack callback);

    virtual bool getNextTestCase(TestCaseCallBack callback) = 0;

protected:
    std::ifstream _fileStream{};
};

template <typename Res, typename... Args>
TestCaseReader<Res(Args...)>::~TestCaseReader() noexcept {
    if (this->_fileStream.is_open()) this->_fileStream.close();
}

template <typename Res, typename... Args>
void TestCaseReader<Res(Args...)>::setFile(std::string_view filePath) {
    if (this->_fileStream.is_open()) this->_fileStream.close();
    this->_fileStream.open(std::string{filePath}, std::ios::out);
}

template <typename Res, typename... Args>
void TestCaseReader<Res(Args...)>::forEachTestCase(TestCaseCallBack callback) {
    while (getNextTestCase(callback));
}

template <typename Res, typename... Args>
class LeetCodeTestCaseReader<Res(Args...)> : public TestCaseReader<Res(Args...)> {
public:
    using TestCaseCallBack = TestCaseReader<Res(Args...)>::TestCaseCallBack;

public:
    explicit LeetCodeTestCaseReader(std::string_view filePath);

    ~LeetCodeTestCaseReader() noexcept override;

    bool getNextTestCase(TestCaseCallBack callback) override;

private:
    template <std::size_t... IS>
    void parseArgsAndSolve(const std::string &input, const std::string &output, std::index_sequence<IS...>, TestCaseCallBack callback) const;
};

template <typename Res, typename... Args>
LeetCodeTestCaseReader<Res(Args...)>::LeetCodeTestCaseReader(std::string_view filePath) : TestCaseReader<Res(Args...)>{filePath} {}

template <typename Res, typename... Args>
LeetCodeTestCaseReader<Res(Args...)>::~LeetCodeTestCaseReader() noexcept = default;

template <typename Res, typename... Args>
bool LeetCodeTestCaseReader<Res(Args...)>::getNextTestCase(TestCaseCallBack callback) {
    std::string input{}, output{};
    std::getline(this->_fileStream, input, '|');
    std::getline(this->_fileStream, output);
    if (!input.empty() && !output.empty()) {
        this->parseArgsAndSolve(input, output, std::index_sequence_for<Args...>{}, callback);
        return true;
    }
    return false;
}

template <typename Res, typename... Args>
template <std::size_t... IS>
void LeetCodeTestCaseReader<Res(Args...)>::parseArgsAndSolve(const std::string &input, const std::string &output, std::index_sequence<IS...>,
                                                             TestCaseCallBack callback) const {
    callback(Parse::parseType<Res>(output), Parse::parseTypeByIndex<IS, Args>(input)...);
}

#endif  // LEETCODE_TEST_CASE_READER_HPP
