/**
  ******************************************************************************
  * @file           : leetcode_task977.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task977.h"

static std::vector<int> sortedSquares1(const std::vector<int> &nums) {
    std::vector<int> result_vec(nums.size(), 0);
    auto mid = nums.cbegin();
    for (; mid != nums.cend() && *mid < 0; ++mid);
    auto rmid = std::reverse_iterator(mid); // reverse_iterator 与 iterator 之间差一个元素 rmid指向的是mid的前一个位置
    auto res = result_vec.begin();
    while (mid != nums.cend() && rmid != nums.crend()) {
        if (*mid > -(*rmid)) {
            *res = (*rmid) * (*rmid);
            ++rmid;
        } else {
            *res = (*mid) * (*mid);
            ++mid;
        }
        ++res;
    }
    while (mid != nums.cend()) {
        *res = (*mid) * (*mid);
        ++mid;
        ++res;
    }
    while (rmid != nums.crend()) {
        *res = (*rmid) * (*rmid);
        ++rmid;
        ++res;
    }
    return result_vec;
}

static std::vector<int> sortedSquares2(const std::vector<int> &nums) {
    std::vector<int> result_vec(nums.size(), 0);
    int left = 0, right = nums.size() - 1;
    auto res_iter = result_vec.rbegin();
    while (left <= right) {
        if ((-nums[left]) > nums[right]) {
            *res_iter = nums[left] * nums[left];
            ++left;
        } else {
            *res_iter = nums[right] * nums[right];
            --right;
        }
        ++res_iter;
    }
    return result_vec;
}

std::vector<int> LeetcodeTask977::solve(const std::vector<int> &nums) const {
    return sortedSquares2(nums);
}