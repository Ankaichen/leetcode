/**
  ******************************************************************************
  * @file           : task96.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK96_HPP
#define LEETCODE_TASK96_HPP

#include "../task.hpp"

class Task96 : public Task<96, int(int)> {
public:
    Task96();

    ~Task96() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同的二叉搜索树";
    }

    [[nodiscard]] int solve(int n) const override;
};

Task96::Task96() {
    this->addTestCase("n = 3", "5");
    this->addTestCase("n = 1", "1");
}

int numTrees1(int n) {
    if (n < 3)
        return n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        int count = 0;
        for (int j = 0; j <= i - 1; ++j) {
            count += dp[j] * dp[i - j - 1];
        }
        dp[i] = count;
    }
    return dp[n];
}

int Task96::solve(int n) const {
    return numTrees1(n);
}

#endif //LEETCODE_TASK96_HPP
