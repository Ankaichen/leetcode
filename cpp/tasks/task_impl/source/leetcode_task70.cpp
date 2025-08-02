/**
  ******************************************************************************
  * @file           : leetcode_task70.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task70.h"

static int count;

static void backtracking(int n) {
    if (n == 0) {
        ++count;
        return;
    }
    if (n - 1 >= 0) backtracking(n - 1);
    if (n - 2 >= 0) backtracking(n - 2);
}

static int climbStairs1(int n) {
    count = 0;
    backtracking(n);
    return count;
}

static int climbStairs2(int n) {
    std::vector<std::vector<int>> dp( // 动态规划数组 向j+1代表走一级台阶 i+1代表走两级台阶
            n / 2 + 2, std::vector<int>(n + 2, 0));
    dp[0][1] = 1;
    int count = 0;
    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j < n + 2; ++j) {
            int pathN = (i - 1) * 2 + (j - 1);
            if (pathN <= n) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (pathN == n) {
                    count += dp[i][j];
                }
            }
        }
    }
    return count;
}

static int climbStairs3(int n) {
    if (n == 0) return 0;
    int dp_1 = 1, dp_2 = 1;
    for (int i = 2; i <= n; ++i) {
        int sum = dp_1 + dp_2;
        dp_1 = dp_2;
        dp_2 = sum;
    }
    return dp_2;
}

int LeetcodeTask70::solve(int n) const {
    return climbStairs3(n);
}