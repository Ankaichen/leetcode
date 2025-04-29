/**
  ******************************************************************************
  * @file           : task541.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-26
  ******************************************************************************
  */

#ifndef LEETCODE_TASK541_HPP
#define LEETCODE_TASK541_HPP

#include "../task.hpp"

class Task541 : public Task<541, std::string(const std::string &, int)> {
public:
    Task541();

    ~Task541() noexcept override = default;

    std::string title() const override {
        return "反转字符串 II";
    }

    std::string solve(const std::string &s, int k) const override;
};

Task541::Task541() {
    this->addTestCase(R"(s = "abcdefg"; k = 2)", R"("bacdfeg")");
    this->addTestCase(R"(s = "abcd"; k = 2)", R"("bacd")");
    this->addTestCase(R"(s = "a"; k = 2)", R"("a")");
    this->addTestCase(R"(s = "abcdefg"; k = 1213)", R"("gfedcba")");
}

std::string reverseStr1(std::string &s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        std::reverse(s.begin() + i, i + k < s.size() ? s.begin() + i + k : s.end());
    }
    return s;
}

std::string reverseStr2(std::string &s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        int end = i + k > s.size() ? static_cast<int>(s.size()) : i + k;
        for (int j = 0; j < (end - i) / 2; ++j) {
            std::swap(s[i + j], s[end - j - 1]);
        }
    }
    return s;
}

std::string Task541::solve(const std::string &s, int k) const {
    return reverseStr2(const_cast<std::string &>(s), k);
}

#endif //LEETCODE_TASK541_HPP
