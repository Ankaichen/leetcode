/**
 ******************************************************************************
 * @file           : core.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-2
 ******************************************************************************
 */

#include <iostream>

#include "../../color_out/color_out.h"
#include "./test_case_reader.hpp"
#include "./test_result_processor.hpp"

static std::size_t maxCellWidth = 35;

// 删除范围内指定字符
std::size_t trimCharInRange(std::string &s, std::string::size_type begin, std::string::size_type end, char c) {
    std::size_t originalSize = s.size();
    s.erase(std::remove(s.begin() + begin, s.begin() + end, c), s.begin() + end);
    return originalSize - s.size();
}

// 自动换行，带缩进（对齐等号）
void wrapLines(std::string &s) {
    if (s.empty()) return;

    std::size_t equalPos = s.find('=');
    std::size_t indent = (equalPos != std::string::npos) ? equalPos + 2 : 0;
    std::string indentStr(indent, ' ');

    std::size_t i = 0;
    while (i < s.size()) {
        std::size_t lineStart = i;
        std::size_t maxEnd = i + maxCellWidth;

        if (indent > 0 && lineStart != 0) {
            maxEnd = lineStart + (maxCellWidth - indent);
        }

        if (maxEnd >= s.size()) break;

        int breakPos = static_cast<int>(s.rfind(',', maxEnd));
        int bracketLeftPos = static_cast<int>(s.rfind('[', maxEnd));
        int bracketRightPos = static_cast<int>(s.rfind(']', maxEnd));
        breakPos = std::max(std::max(breakPos, bracketLeftPos), bracketRightPos);

        if (breakPos == std::string::npos || breakPos <= lineStart) breakPos = maxEnd;

        s.insert(breakPos + 1, "\n" + indentStr);
        i = breakPos + 1 + 1 + indent;
    }
}

// 主处理逻辑
void formatInputOutputString(std::string &input, std::string &output) {
    auto process = [](std::string &str) {
        if (str.empty()) return;

        std::size_t start = 0;
        while (start < str.size()) {
            std::size_t end = str.find(';', start);
            bool isLast = (end == std::string::npos);
            if (isLast)
                end = str.size();
            else
                str[end] = '\n';
            std::size_t eqPos = str.find('=', start);
            std::size_t nextEqPos = str.find('=', end);
            std::size_t trimcount =
                trimCharInRange(str, eqPos != std::string::npos ? eqPos + 2 : start, nextEqPos != std::string::npos ? nextEqPos - 2 : end, ' ');
            start = end - trimcount + 1;
        }
        std::ostringstream oss;
        std::istringstream iss{str};
        std::string temp;
        while (std::getline(iss, temp, '\n')) {
            wrapLines(temp);
            oss << temp << "\n";
        }
        str = std::move(oss).str();
        str.pop_back();
    };

    process(input);
    process(output);
}

bool ACMTestCaseReader::getNextTestCase(TestCaseReader<std::ostringstream &(std::istringstream &)>::TestCaseCallBack callback,
                                        TestCaseReader<std::ostringstream &(std::istringstream &)>::TestCaseStringCallBack stringCallback) {
    std::string line{};
    std::ostringstream iss{}, oss{};
    bool isI = true;
    while (std::getline(this->_fileStream, line, '\n')) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        if (line.find('#') != std::string::npos) break;
        if (line == ">>") {
            isI = true;
            continue;
        }
        if (line == "<<") {
            isI = false;
            continue;
        }
        if (isI) {
            iss << line << "\n";
        } else {
            oss << line << "\n";
        }
    }
    std::istringstream iss_i{iss.str()};
    if (callback != nullptr) callback(oss, iss_i);
    if (stringCallback != nullptr) {
        std::string ossStr{oss.str()}, issStr{iss.str()};
        ossStr.pop_back();
        issStr.pop_back();
        stringCallback(issStr, ossStr);
    }
    return !this->_fileStream.eof();
}

ListNodeTestResultProcessor::CleanOutputType ListNodeTestResultProcessor::processResult(
    const ListNodeTestResultProcessor::CleanInputType &input) const {
    CleanOutputType output = input;
    const_cast<CleanInputType &>(input) = nullptr;
    return output;
}

ACMTestResultProcessor::CleanOutputType ACMTestResultProcessor::processResult(CleanInputType &input) const { return input; }