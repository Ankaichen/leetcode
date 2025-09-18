/**
 ******************************************************************************
 * @file           : leetcode_task494.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-25
 ******************************************************************************
 */

#include "../include/leetcode_task494.h"

static int findTargetSumWays1(const std::vector<int>& nums, int target) {
    // 回溯法
    int result = 0;
    auto backtracking = [&nums, target, &result](auto& self, int start, int cur_target) -> void {
        if (start >= nums.size() && cur_target == target) ++result;
        if (start >= nums.size()) return;
        self(self, start + 1, cur_target + nums[start]);
        self(self, start + 1, cur_target - nums[start]);
    };
    backtracking(backtracking, 0, 0);
    return result;
}

static int findTargetSumWays2(const std::vector<int>& nums, int target) {
    // 动态规划
    // 题目要求可以视为 将数组分为 left 和 right 两部分 满足 left - right = target; left + right = sum;
    // 可知 right = left - target; -> left + (left - target) = sum; -> left = (sum + target) / 2;
    // 此时 可将本题视为01背包问题 背包容量为(sum + target) / 2
    target = std::accumulate(nums.begin(), nums.end(), std::abs(target));  // target 取绝对值 结果不变
    if (target % 2 == 1) return 0;
    target /= 2;  // 计算 (sum + target) / 2
    std::vector<std::vector<int>> dp(target + 1, std::vector<int>(nums.size() + 1, 0));
    dp[0][0] = 1;
    int zeroCount = 1;
    for (int i = 1; i <= nums.size(); ++i) {
        if (nums[i - 1] == 0) zeroCount *= 2;  // 处理存在0的情况 出现一次0 则可能的次数翻倍
        dp[0][i] = zeroCount;
    }
    for (int i = 1; i <= target; ++i) {
        for (int j = 1; j <= nums.size(); ++j) {
            dp[i][j] = dp[i][j - 1];
            if (nums[j - 1] <= i) {
                dp[i][j] += dp[i - nums[j - 1]][j - 1];
            }
        }
    }
    return dp[target][nums.size()];
}

static int findTargetSumWays3(const std::vector<int>& nums, int target) {
    // 动态规划 一维数组
    target = std::accumulate(nums.begin(), nums.end(), std::abs(target));
    if (target % 2 == 1) return 0;
    target /= 2;
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;
    int zeroCount = 1;
    for (int j = 1; j <= nums.size(); ++j) {
        for (int i = target; i >= 1; --i) {
            if (nums[j - 1] <= i) {
                dp[i] += dp[i - nums[j - 1]];
            }
        }
        if (nums[j - 1] == 0) zeroCount *= 2;
        dp[0] = zeroCount;
    }
    return dp[target];
}

int LeetcodeTask494::solve(const std::vector<int>& nums, int target) const { return findTargetSumWays3(nums, target); }