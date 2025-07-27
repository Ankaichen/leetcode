/**
  ******************************************************************************
  * @file           : task27.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task27.h"

Task27::Task27() {
    this->addTestCase("nums = [3,2,2,3]; val = 3", "2");
    this->addTestCase("nums = [0,1,2,2,3,0,4,2]; val = 2", "5");
}

static int removeElement1(std::vector<int> &nums, int val) {
    int low = 0, high = 0;
    for (; high < nums.size(); ++high) {
        if (nums[high] != val) {
            nums[low++] = nums[high];
        }
    }
    return low;
}

int Task27::solve(const std::vector<int> &nums, int val) const {
    return removeElement1(const_cast<std::vector<int> &>(nums), val);
}