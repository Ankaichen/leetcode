/**
  ******************************************************************************
  * @file           : leetcode_task343.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task343.h"

static void backtracking(int n, int times, int &result) {
    if (n == 0)
        result = std::max(result, times);
    for (int i = 1; i <= n; ++i) {
        backtracking(n - i, times * i, result);
    }
}

static int integerBreak1(int n) {
    int result = 0;
    for (int i = 1; i < n; ++i) {
        backtracking(n - i, i, result);
    }
    return result;
}

static int integerBreak2(int n) {
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

int LeetcodeTask343::solve(int n) const {
    return integerBreak1(n);
}