/**
  ******************************************************************************
  * @file           : leetcode_task18.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task18.h"

static std::vector<std::vector<int>> fourSum1(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > target && nums[i] >= 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = static_cast<int>(nums.size()) - 1;
            while (left < right) {
                if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] < target) {
                    ++left;
                } else if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] > target) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    for (++left; left < right && nums[left] == nums[left - 1]; ++left);
                    for (--right; left < right && nums[right] == nums[right + 1]; --right);
                }
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> LeetcodeTask18::solve(const std::vector<int> &nums, int target) const {
    return fourSum1(const_cast<std::vector<int> &>(nums), target);
}