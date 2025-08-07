/**
 ******************************************************************************
 * @file           : leetcode_task53.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-7
 ******************************************************************************
 */

#include "../include/leetcode_task53.h"

static int maxSubArray2(std::vector<int>& nums) {
    // 动态规划：只要求返回结果，不要求得到最大的连续子数组是哪一个 这种问题适用于动态规划
    // 定义子问题：对于子问题的定义需要有「无后效性」，即已经求解的子问题不受后续阶段的影响
    // 在这个问题中，如果将子问题定义为「经过nums[i]的最大的连续子数组长度」的话，就不满足无后效性
    // 因此需要将子问题修改为「以nums[i]结尾的最大的连续子数组长度」，在求得dp数组后，再由dp数组求解最终结果
    std::vector<int> dp{nums.begin(), nums.end()};
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
    }
    int result = 0x80000000;
    for (const auto& i : dp) {
        result = std::max(i, result);
    }
    return result;
}

static int maxSubArray1(std::vector<int>& nums) {
    int maxSum = 0x80000000;
    for (int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j) {
            sum += nums[j];
            maxSum = std::max(maxSum, sum);
        }
    }
    return maxSum;
}

int LeetcodeTask53::solve(const std::vector<int>& nums) const { return maxSubArray2(const_cast<std::vector<int>&>(nums)); }