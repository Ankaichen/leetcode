/**
  ******************************************************************************
  * @file           : task17.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK17_HPP
#define LEETCODE_TASK17_HPP

#include "../task.hpp"

class Task17 : public Task<17, std::set<std::string>(const std::string&)> {
public:
    Task17();
    ~Task17() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "电话号码的字母组合";
    }
    [[nodiscard]] std::set<std::string> solve(const std::string& digits) const override;
};

Task17::Task17() {
    this->addTestCase(R"(digits = "23")", R"({"ad","ae","af","bd","be","bf","cd","ce","cf"})");
    this->addTestCase(R"(digits = "")", R"({})");
    this->addTestCase(R"(digits = "2")", R"({"a","b","c"})");
//    this->addTestCase(R"(digits = "25546973")", R"({"a","b","c"})");
}

void backtracking(const std::string &digits, const std::array<std::string, 8> &numStrMap, std::vector<char> &str, std::vector<std::string> &result) {
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

std::vector<std::string> letterCombinations1(const std::string &digits) {
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

#endif //LEETCODE_TASK17_HPP
