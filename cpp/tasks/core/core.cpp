/**
 ******************************************************************************
 * @file           : core.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-2
 ******************************************************************************
 */

#include "./test_case_reader.hpp"
#include "./test_result_processor.hpp"

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