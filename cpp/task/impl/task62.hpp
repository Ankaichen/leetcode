/**
  ******************************************************************************
  * @file           : task62.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK62_HPP
#define LEETCODE_TASK62_HPP

#include "../task.hpp"

class Task62 : public Task<62, int(int, int)> {
public:
    Task62();

    ~Task62() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同路径";
    }

    [[nodiscard]] int solve(int m, int n) const override;
};

Task62::Task62() {
    this->addTestCase("m = 3; n = 7", "28");
    this->addTestCase("m = 3; n = 2", "3");
}

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int Task62::solve(int m, int n) const {
    return uniquePaths(m, n);
}

#endif //LEETCODE_TASK62_HPP
