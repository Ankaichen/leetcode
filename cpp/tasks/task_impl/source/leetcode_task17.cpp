/**
  ******************************************************************************
  * @file           : leetcode_task17.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task17.h"

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

std::vector<std::string> LeetcodeTask17::solve(const std::string &digits) const {
    return letterCombinations1(digits);
}