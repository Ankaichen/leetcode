/**
  ******************************************************************************
  * @file           : task343.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK343_HPP
#define LEETCODE_TASK343_HPP

#include "../task.hpp"

class Task343 : public Task<343, int(int)> {
public:
    Task343();

    ~Task343() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "整数拆分";
    }

    [[nodiscard]] int solve(int n) const override;
};

Task343::Task343() {
    this->addTestCase("n = 2", "1");
    this->addTestCase("n = 10", "36");
    this->addTestCase("n = 30", "59049");
//    this->addTestCase("n = 100", "2124471432");
}

void backtracking(int n, int times, int &result) {
    if (n == 0)
        result = std::max(result, times);
    for (int i = 1; i <= n; ++i) {
        backtracking(n - i, times * i, result);
    }
}

int integerBreak1(int n) {
    int result = 0;
    for (int i = 1; i < n; ++i) {
        backtracking(n - i, i, result);
    }
    return result;
}

int integerBreak2(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int maxj = dp[i - 1];
        for (int j = 1; j < i; ++j) {
            int i1 = std::max(dp[j], j);
            int i2 = std::max(dp[i - j], i - j);
            maxj = std::max(maxj, i1 * i2);
        }
        dp[i] = maxj;
    }
    return dp[n];
}

int Task343::solve(int n) const {
    return integerBreak1(n);
}

#endif //LEETCODE_TASK343_HPP
