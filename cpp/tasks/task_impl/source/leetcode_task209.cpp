/**
  ******************************************************************************
  * @file           : leetcode_task209.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task209.h"

static int minSubArrayLen1(int target, const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0] > target ? 1 : 0;
    int left = 0, right = 1;
    int sum = nums[0];
    int bestLen = static_cast<int>(nums.size() + 1);
    while (right < nums.size()) {
        while (sum < target && right < nums.size()) {
            sum += nums[right];
            ++right;
        }
        while (sum >= target && left < right) {
            bestLen = std::min(bestLen, right - left);
            sum -= nums[left];
            ++left;
        }
    }
    return (bestLen == nums.size() + 1) ? 0 : bestLen;
}

static int minSubArrayLen2(int target, const std::vector<int> &nums) {
    int left = 0, right = 0;
    int sum = 0;
    int bestLen = static_cast<int>(nums.size() + 1);
    while (right < nums.size()) {
        while (sum < target && right < nums.size()) {
            sum += nums[right++];
        }
        while (sum >= target) {
            bestLen = std::min(bestLen, right - left);
            sum -= nums[left++];
        }
    }
    return (bestLen == nums.size() + 1) ? 0 : bestLen;
}

int LeetcodeTask209::solve(int target, const std::vector<int> &nums) const {
    return minSubArrayLen2(target, nums);
}