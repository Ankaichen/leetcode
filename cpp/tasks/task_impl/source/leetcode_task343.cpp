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

static int integerBreak1(int n) {
    // 回溯法
    int result = 0;
    auto backtracking = [n, &result](auto &self, int cur_sum, int cur_res, int cur) -> void {
        if (cur_sum == n) result = std::max(result, cur_res);
        if (cur_sum >= n) return;
        for (int i = cur; i <= n - cur_sum; ++i) {
            self(self, cur_sum + i, cur_res * i, i);
        }
    };
    for (int i = 1; i < n; ++i) {
        backtracking(backtracking, i, i, i);
    }
    return result;
}

static int integerBreak2(int n) {
    // 动态规划 dp[i]表示n=i时的输出结果 每次通过比较之前所有的dp值 计算当前dp值
    std::vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = i - 1; j >= 1; --j) {
            dp[i] = std::max(std::max(dp[j] * (i - j), j * (i - j)), dp[i]);
        }
    }
    return dp[n];
}

static int integerBreak3(int n) {
    // 通过static保留每次计算结果 多个用例只需计算一次
    static std::vector<int> dp(59, 1);
    static int i = 2;
    for (; i <= n; ++i) {
        dp[i] = 0;
        for (int j = i - 1; j >= 1; --j) {
            dp[i] = std::max(std::max(dp[j] * (i - j), j * (i - j)), dp[i]);
        }
    }
    return dp[n];
}

int LeetcodeTask343::solve(int n) const { return integerBreak3(n); }