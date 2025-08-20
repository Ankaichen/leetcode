/**
 ******************************************************************************
 * @file           : leetcode_task63.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-6-19
 ******************************************************************************
 */

#include "../include/leetcode_task63.h"

static int uniquePathsWithObstacles1(const std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1] == 1) continue;
            int count1 = i - 2 >= 0 && obstacleGrid[i - 2][j - 1] == 1 ? 0 : dp[i - 1][j];
            int count2 = j - 2 >= 0 && obstacleGrid[i - 1][j - 2] == 1 ? 0 : dp[i][j - 1];
            dp[i][j] = count1 + count2;
        }
    }
    return dp[m][n];
}

static int uniquePathsWithObstacles2(const std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1] == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

static int uniquePathsWithObstacles3(const std::vector<std::vector<int>> &obstacleGrid) {
    // 回溯法
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int result = 0;
    auto backtracking = [m, n, &obstacleGrid, &result](auto &self, int m_i, int n_i) -> void {
        if (m_i > m || n_i > n || obstacleGrid[m_i - 1][n_i - 1] == 1) return;
        if (m_i == m && n_i == n) {
            ++result;
            return;
        }
        self(self, m_i + 1, n_i);
        self(self, m_i, n_i + 1);
    };
    backtracking(backtracking, 1, 1);
    return result;
}

static int uniquePathsWithObstacles4(const std::vector<std::vector<int>> &obstacleGrid) {
    // 动态规划 参考leetcode task 62 每次计算dp数组考虑是否有障碍物
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, obstacleGrid[0][0] == 1 ? 0 : 1));
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 1)
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

static int uniquePathsWithObstacles5(const std::vector<std::vector<int>> &obstacleGrid) {
    // 动态规划 一维dp数组
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<int> dp(n, obstacleGrid[0][0] == 1 ? 0 : 1);
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 1)
            dp[j] = 0;
        else
            dp[j] = dp[j - 1];
    }
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 1) dp[0] = 0;
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 1)
                dp[j] = 0;
            else
                dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[n - 1];
}

int LeetcodeTask63::solve(const std::vector<std::vector<int>> &obstacleGrid) const { return uniquePathsWithObstacles5(obstacleGrid); }