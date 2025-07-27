/**
  ******************************************************************************
  * @file           : task17.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task17.h"

Task17::Task17() {
    this->addTestCase(R"(digits = "23")", R"({"ad","ae","af","bd","be","bf","cd","ce","cf"})");
    this->addTestCase(R"(digits = "")", R"({})");
    this->addTestCase(R"(digits = "2")", R"({"a","b","c"})");
//    this->addTestCase(R"(digits = "25546973")", R"({"a","b","c"})");
}

static void backtracking(const std::string &digits, const std::array<std::string, 8> &numStrMap, std::vector<char> &str, std::vector<std::string> &result) {
    int index = str.size();
    if (index >= digits.size()) {
        result.emplace_back(str.cbegin(), str.cend());
        return;
    }
    for (char c : numStrMap[digits[index] - '2']) {
        str.push_back(c);
        backtracking(digits, numStrMap, str, result);
        str.pop_back();
    }
}

static std::vector<std::string> letterCombinations1(const std::string &digits) {
    if (digits.empty()) return {};
    std::array<std::string, 8> numStrMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<char> str;
    std::vector<std::string> result;
    backtracking(digits, numStrMap, str, result);
    return result;
}

std::set<std::string> Task17::solve(const std::string &digits) const {
    std::vector<std::string> result = letterCombinations1(digits);
    std::set<std::string> strSet(result.cbegin(), result.cend());
    return strSet;
}