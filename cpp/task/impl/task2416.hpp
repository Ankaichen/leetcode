/**
  ******************************************************************************
  * @file           : task2416.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-30
  ******************************************************************************
  */

#ifndef LEETCODE_TASK2416_HPP
#define LEETCODE_TASK2416_HPP

#include "../task.hpp"

class Task2416 : public Task<2416, std::vector<int>(const std::vector<std::string>&)> {
public:
    Task2416();
    ~Task2416() noexcept override = default;
    std::string title() const override {
        return "字符串的前缀分数和";
    }
    std::vector<int> solve(const std::vector<std::basic_string<char>> &words) const override;
};

Task2416::Task2416() {
    this->addTestCase(R"(words = ["abc","ab","bc","b"])", "[5,4,3,2]");
    this->addTestCase(R"(words = ["abcd"])", "[4]");
}

bool isPrefix(const std::string& str, const std::string& prefix) {
    if (str.size() < prefix.size())
        return false;
    for (int i = 0; i < prefix.size(); ++i) {
        if (str[i] != prefix[i])
            return false;
    }
    return true;
}

std::vector<int> sumPrefixScores(std::vector<std::string>& words) {
    std::vector<int> result(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 1; j <= words[i].size(); ++j) {
            for (int k = 0; k < words.size(); ++k) {
                result[i] += isPrefix(words[k], words[i].substr(0, j));
            }
        }
    }
    return result;
}

std::vector<int> Task2416::solve(const std::vector<std::string> &words) const {
    return sumPrefixScores(const_cast<std::vector<std::string>&>(words));
}

#endif //LEETCODE_TASK2416_HPP
