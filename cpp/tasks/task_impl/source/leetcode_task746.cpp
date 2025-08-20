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
    int dpI = cost.size() / 2 + 3, dpJ = cost.size() + 3;  // dp 表示到达每个位置的最小花费
    std::vector<std::vector<int>> dp(dpI, std::vector<int>(dpJ, 999999));
    dp[1][1] = 0;
    int result = 9990000;
    for (int i = 1; i < dpI; ++i) {
        for (int j = 1; j < dpJ; ++j) {
            int curStep = (i - 1) * 2 + j - 1 - 1;
            if (curStep > cost.size() || curStep < 0) continue;
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
    // 动态规划 dp数据表示到达第i层的最小花费 等于到达前一层的花费与前一层花费 与 到达前两层的花费与前两层花费 的最小值
    std::vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = std::min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[cost.size()];
}

static int minCostClimbingStairs3(const std::vector<int> &cost) {
    // 由于每次计算只需要dp[i-1]和dp[i-2] 因此可以用两个变量代替dp数组
    int dp_0 = 0, dp_1 = 0;
    for (int i = 2; i <= cost.size(); ++i) {
        dp_0 = std::min(dp_0 + cost[i - 2], dp_1 + cost[i - 1]);
        std::swap(dp_0, dp_1);
    }
    return dp_1;
}

static int minCostClimbingStairs4(const std::vector<int> &cost) {
    // 回溯法
    int result = 0x7fffffff;
    auto backtracking = [&cost, &result](auto &self, int start, int cur_cost) -> void {
        if (start >= cost.size()) {
            result = std::min(result, cur_cost);
            return;
        }
        self(self, start + 1, cur_cost + cost[start]);
        self(self, start + 2, cur_cost + cost[start]);
    };
    backtracking(backtracking, 0, 0);
    backtracking(backtracking, 1, 0);
    return result;
}

int LeetcodeTask746::solve(const std::vector<int> &cost) const { return minCostClimbingStairs3(cost); }