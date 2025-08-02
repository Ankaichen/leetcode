/**
  ******************************************************************************
  * @file           : leetcode_task704.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task704.h"

static int search1(const std::vector<int> &nums, int target) {
    int low = 0, high = static_cast<int>(nums.size() - 1);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int LeetcodeTask704::solve(const std::vector<int> &nums, int target) const {
    return search1(nums, target);
}
