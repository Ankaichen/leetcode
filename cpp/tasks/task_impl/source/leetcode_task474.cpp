/**
 ******************************************************************************
 * @file           : leetcode_task474.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-9-19
 ******************************************************************************
 */

#include "../include/leetcode_task474.h"

static int findMaxForm1(const std::vector<std::string>& strs, int m, int n) {
    // 回溯法
    int result = 0;
    std::vector<std::pair<int, int>> str_nums(strs.size(), std::make_pair(-1, -1));
    for (int i = 0; i < strs.size(); ++i) {
        int c0 = 0, c1 = 0;
        for (char c : strs[i]) {
            if (c == '0')
                ++c0;
            else if (c == '1')
                ++c1;
        }
        str_nums[i].first = c0;
        str_nums[i].second = c1;
    }
    auto backtracking = [&str_nums, m, n, &result](auto& self, int cur, int cur_res, int cur_m, int cur_n) -> void {
        if (cur >= str_nums.size()) {
            if (cur_m <= m && cur_n <= n) {
                result = std::max(result, cur_res);
            } else {
                return;
            }
        } else {
            if (cur_m > m || cur_n > n) {
                return;
            }
            self(self, cur + 1, cur_res, cur_m, cur_n);
            self(self, cur + 1, cur_res + 1, cur_m + str_nums[cur].first, cur_n + str_nums[cur].second);
        }
    };
    backtracking(backtracking, 0, 0, 0, 0);
    return result;
}

static int findMaxForm2(const std::vector<std::string>& strs, int m, int n) {
    // 动态规划 3维dp数组
    std::vector<std::pair<int, int>> str_nums(strs.size(), std::make_pair(-1, -1));
    for (int i = 0; i < strs.size(); ++i) {
        int c0 = 0, c1 = 0;
        for (char c : strs[i]) {
            if (c == '0')
                ++c0;
            else if (c == '1')
                ++c1;
        }
        str_nums[i].first = c0;
        str_nums[i].second = c1;
    }
    std::vector<std::vector<std::vector<int>>> dp(m + 1, std::vector<std::vector<int>>(n + 1, std::vector<int>(strs.size() + 1, 0)));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 1; k <= strs.size(); ++k) {
                dp[i][j][k] = dp[i][j][k - 1];
                if (str_nums[k - 1].first <= i && str_nums[k - 1].second <= j) {
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - str_nums[k - 1].first][j - str_nums[k - 1].second][k - 1] + 1);
                }
            }
        }
    }
    return dp[m][n][strs.size()];
}

static int findMaxForm3(const std::vector<std::string>& strs, int m, int n) {
    // 动态规划 2维dp数组
    std::vector<std::pair<int, int>> str_nums(strs.size(), std::make_pair(-1, -1));
    for (int i = 0; i < strs.size(); ++i) {
        int c0 = 0, c1 = 0;
        for (char c : strs[i]) {
            if (c == '0')
                ++c0;
            else if (c == '1')
                ++c1;
        }
        str_nums[i].first = c0;
        str_nums[i].second = c1;
    }
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int k = 1; k <= strs.size(); ++k) {
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (str_nums[k - 1].first <= i && str_nums[k - 1].second <= j) {
                    dp[i][j] = std::max(dp[i][j], dp[i - str_nums[k - 1].first][j - str_nums[k - 1].second] + 1);
                }
            }
        }
    }
    return dp[m][n];
}

static int findMaxForm4(const std::vector<std::string>& strs, int m, int n) {
    // 动态规划 2维dp数组 2维数组版本可省略 std::vector<std::pair<int, int>>
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (const auto& str : strs) {
        int c0 = 0, c1 = 0;
        for (char c : str) {
            if (c == '0')
                ++c0;
            else if (c == '1')
                ++c1;
        }
        for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
                if (c0 <= i && c1 <= j) {
                    dp[i][j] = std::max(dp[i][j], dp[i - c0][j - c1] + 1);
                }
            }
        }
    }
    return dp[m][n];
}

int LeetcodeTask474::solve(const std::vector<std::string>& strs, int m, int n) const { return findMaxForm4(strs, m, n); }