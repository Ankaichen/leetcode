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
    // 动态规划 01背包问题 选出以总重量一半为最大容量的物体 然后用总重量减该值的2倍
    int stones_sum = 0, stones_sum_half;
    stones_sum = std::accumulate(stones.begin(), stones.end(), stones_sum);
    stones_sum_half = stones_sum / 2;
    std::vector<std::vector<int>> dp(stones.size() + 1, std::vector<int>(stones_sum_half + 1, 0));
    for (int i = 1; i <= stones.size(); ++i) {
        for (int j = 1; j <= stones_sum_half; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (stones[i - 1] <= j) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
    }
    return stones_sum - 2 * dp[stones.size()][stones_sum_half];
}

static int lastStoneWeightII2(const std::vector<int> &stones) {
    // 动态规划 1维dp数组
    int stones_sum = 0, stones_sum_half;
    stones_sum = std::accumulate(stones.begin(), stones.end(), stones_sum);
    stones_sum_half = stones_sum / 2;
    std::vector<int> dp(stones_sum_half + 1, 0);
    for (int i = 1; i <= stones.size(); ++i) {
        for (int j = stones_sum_half; j >= 1; --j) {
            if (stones[i - 1] <= j) {
                dp[j] = std::max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
            }
        }
    }
    return stones_sum - 2 * dp[stones_sum_half];
}

int LeetcodeTask1049::solve(const std::vector<int> &stones) const { return lastStoneWeightII2(stones); }
