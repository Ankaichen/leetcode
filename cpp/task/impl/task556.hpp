/**
  ******************************************************************************
  * @file           : task556.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-29
  ******************************************************************************
  */

#ifndef LEETCODE_TASK556_HPP
#define LEETCODE_TASK556_HPP

#include "../task.hpp"

class Task556 : public Task<556, int(int)> {
public:
    Task556();

    ~Task556() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "下一个更大元素 III";
    }

    [[nodiscard]] int solve(int n) const override;
};

Task556::Task556() {
    this->addTestCase("n = 12", "21");
    this->addTestCase("n = 21", "-1");
}

int nextGreaterElement1(int n) {
    if (n < 10) return -1;
    std::string s = std::to_string(n);
    int i = s.size() - 2;
    for (; i >= 0 && s[i] >= s[i + 1]; --i);
    if (i >= 0) {
        int j = s.size() - 1;
        for (; j > i && s[j] <= s[i]; --j);
        std::swap(s[i], s[j]);
        std::reverse(s.begin() + 1 + i, s.end());
        long res = std::stol(s);
        return res > 0x7fffffff ? -1 : res;
    } else {
        return -1;
    }
}

int Task556::solve(int n) const {
    return nextGreaterElement1(n);
}

#endif //LEETCODE_TASK556_HPP
