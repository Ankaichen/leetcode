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

static int uniquePaths1(int m, int n) {
    // 动态规划 dp数组表示到达每个位置的路径数量 等于其左侧位置路径数量与上方位置路径数量的和
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

static int uniquePaths2(int m, int n) {
    // 动态规划 dp数组表示到达每个位置的路径数量 等于其左侧位置路径数量与上方位置路径数量的和
    // 每次计算dp值 覆盖之前计算的值 可以简化为1维dp数组
    std::vector<int> dp(n, 1);
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[n - 1];
}

static int uniquePaths3(int m, int n) {
    // 回溯法 每次可以向下或向右走 起点为(1,1) 终点为(m,n)
    int result = 0;
    auto backtracking = [m, n, &result](auto &self, int m_i, int n_i) -> void {
        if (m_i == m && n_i == n) ++result;
        if (m_i > m || n_i > n) return;
        self(self, m_i + 1, n_i);
        self(self, m_i, n_i + 1);
    };
    backtracking(backtracking, 1, 1);
    return result;
}

int LeetcodeTask62::solve(int m, int n) const { return uniquePaths3(m, n); }