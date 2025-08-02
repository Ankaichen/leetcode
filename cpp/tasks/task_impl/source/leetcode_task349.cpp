/**
  ******************************************************************************
  * @file           : leetcode_task349.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task349.h"

static std::vector<int> intersection(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::set set1(nums1.begin(), nums1.end());
    std::set set2(nums2.begin(), nums2.end());
    std::vector<int> result;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

std::vector<int> LeetcodeTask349::solve(const std::vector<int> &num1, const std::vector<int> &num2) const {
    return intersection(num1, num2);
}