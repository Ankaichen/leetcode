/**
 ******************************************************************************
 * @file           : leetcode_task416.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-6-19
 ******************************************************************************
 */

#include "../include/leetcode_task416.h"

static bool canPartition1(const std::vector<int> &nums) {
    // 动态规划 首先计算nums总和 然后使用01背包思路 求解能否满足nums_sum / 2
    int nums_sum = 0, nums_sum_half;
    nums_sum = std::accumulate(nums.begin(), nums.end(), nums_sum);
    if (nums_sum % 2 != 0) return false;
    nums_sum_half = nums_sum / 2;
    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(nums_sum + 1, 0));
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= nums_sum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i - 1] <= j) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
            if (dp[i][j] == nums_sum_half) return true;
        }
    }
    return false;
}

static bool canPartition2(const std::vector<int> &nums) {
    // 动态规划 一维dp数组
    int nums_sum = 0, nums_sum_half;
    nums_sum = std::accumulate(nums.begin(), nums.end(), nums_sum);
    if (nums_sum % 2 != 0) return false;
    nums_sum_half = nums_sum / 2;
    std::vector<int> dp(nums_sum + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = nums_sum; j >= 1; --j) {
            if (nums[i - 1] <= j) {
                dp[j] = std::max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
            }
            if (dp[j] == nums_sum_half) return true;
        }
    }
    return false;
}

static bool canPartition3(const std::vector<int> &nums) {
    // 回溯法
    int result = false;
    int nums_sum = 0;
    nums_sum = std::accumulate(nums.begin(), nums.end(), nums_sum);
    auto backtracking = [&result, &nums, nums_sum](auto &self, int start, int sum1, int sum2) -> void {
        if (start >= nums.size()) {
            if (sum1 == sum2) result = true;
            return;
        }
        if (std::abs(sum1 - sum2) > nums_sum - sum1 - sum2) return;
        if (!result) self(self, start + 1, sum1 + nums[start], sum2);
        if (!result) self(self, start + 1, sum1, sum2 + nums[start]);
    };
    backtracking(backtracking, 0, 0, 0);
    return result;
}

bool LeetcodeTask416::solve(const std::vector<int> &nums) const { return canPartition2(nums); }