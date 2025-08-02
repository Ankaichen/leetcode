/**
  ******************************************************************************
  * @file           : leetcode_task27.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task27.h"

static int removeElement1(std::vector<int> &nums, int val) {
    int low = 0, high = 0;
    for (; high < nums.size(); ++high) {
        if (nums[high] != val) {
            nums[low++] = nums[high];
        }
    }
    return low;
}

int LeetcodeTask27::solve(const std::vector<int> &nums, int val) const {
    return removeElement1(const_cast<std::vector<int> &>(nums), val);
}