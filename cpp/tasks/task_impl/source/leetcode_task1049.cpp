/**
  ******************************************************************************
  * @file           : leetcode_task1049.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task1049.h"

static int lastStoneWeightII1(const std::vector<int> &stones) {
    int sum = 0;
    for (int i: stones) sum += i;
    int n = sum / 2;
    std::vector<std::vector<int>> dp(stones.size() + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= stones.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= stones[i - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
    }
    return sum - 2 * dp[stones.size()][n];
}

int LeetcodeTask1049::solve(const std::vector<int> &stones) const {
    return lastStoneWeightII1(stones);
}
