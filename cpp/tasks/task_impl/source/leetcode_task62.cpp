/**
  ******************************************************************************
  * @file           : leetcode_task62.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task62.h"

static int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int LeetcodeTask62::solve(int m, int n) const {
    return uniquePaths(m, n);
}