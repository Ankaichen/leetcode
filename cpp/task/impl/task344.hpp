/**
  ******************************************************************************
  * @file           : task344.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-26
  ******************************************************************************
  */

#ifndef LEETCODE_TASK344_HPP
#define LEETCODE_TASK344_HPP

#include "../task.hpp"

class Task344 : public Task<344, std::vector<char>(const std::vector<char>&)> {
public:
    Task344();
    ~Task344() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "反转字符串";
    }
    [[nodiscard]] std::vector<char> solve(const std::vector<char> &s) const override;
};

Task344::Task344() {
    this->addTestCase("s = [h,e,l,l,o]", "[o,l,l,e,h]");
    this->addTestCase("s = [H,a,n,n,a,h]", "[h,a,n,n,a,H]");
}

void reverseString1(std::vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        std::swap(s[i], s[s.size() - i - 1]);
    }
}

void reverseString2(std::vector<char>& s) {
    std::reverse(s.begin(), s.end());
}

std::vector<char> Task344::solve(const std::vector<char> &s) const {
    std::vector<char> input(s.begin(), s.end());
    reverseString1(input);
    return input;
}

#endif //LEETCODE_TASK344_HPP
