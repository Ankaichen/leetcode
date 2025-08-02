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
    if (nums.size() <= 1) return false;
    int sum = 0;
    for (int i: nums) sum += i;
    if (sum % 2 == 1) return false;
    int n = sum / 2;
    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
            if (dp[i][j] == n) {
                return true;
            }
        }
    }
    return false;
}

bool LeetcodeTask416::solve(const std::vector<int> &nums) const {
    return canPartition1(nums);
}