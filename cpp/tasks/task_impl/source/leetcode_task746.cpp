/**
  ******************************************************************************
  * @file           : leetcode_task746.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task746.h"

static int minCostClimbingStairs1(const std::vector<int> &cost) {
    // i 表示走两级台阶 j 表示走一级台阶 起始位置和结束位置
    int dpI = cost.size() / 2 + 3, dpJ = cost.size() + 3; // dp 表示到达每个位置的最小花费
    std::vector<std::vector<int>> dp(dpI, std::vector<int>(dpJ, 999999));
    dp[1][1] = 0;
    int result = 9990000;
    for (int i = 1; i < dpI; ++i) {
        for (int j = 1; j < dpJ; ++j) {
            int curStep = (i - 1) * 2 + j - 1 - 1;
            if (curStep > cost.size() || curStep < 0)
                continue;
            int value1 = dp[i][j - 1], value2 = dp[i - 1][j];
            if (curStep - 1 >= 0) {
                value1 += cost[curStep - 1];
            }
            if (curStep - 2 >= 0) {
                value2 += cost[curStep - 2];
            }
            dp[i][j] = std::min(value1, value2);
            if (curStep == cost.size()) result = std::min(result, dp[i][j]);
        }
    }
    return result;
}

static int minCostClimbingStairs2(const std::vector<int> &cost) {
    std::vector<int> dp(cost.size() + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}

static int minCostClimbingStairs3(const std::vector<int> &cost) {
    int dp_1 = 0, dp_2 = 0;
    for (int i = 2; i <= cost.size(); ++i) {
        int temp = dp_2;
        dp_2 = std::min(dp_2 + cost[i - 1], dp_1 + cost[i - 2]);
        dp_1 = temp;
    }
    return dp_2;
}

int LeetcodeTask746::solve(const std::vector<int> &cost) const {
    return minCostClimbingStairs3(cost);
}