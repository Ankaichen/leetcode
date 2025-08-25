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
    target = std::abs(target);
    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(target, 1));
    for (int i = 0)
}

int LeetcodeTask494::solve(const std::vector<int>& nums, int target) const { return findTargetSumWays2(nums, target); }