/**
  ******************************************************************************
  * @file           : task349.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task349.h"

Task349::Task349() {
    this->addTestCase("nums1 = [1,2,2,1]; nums2 = [2,2]", "{2}");
    this->addTestCase("nums1 = [4,9,5]; nums2 = [9,4,9,8,4]", "{9,4}");
}

static std::vector<int> intersection(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::set set1(nums1.begin(), nums1.end());
    std::set set2(nums2.begin(), nums2.end());
    std::vector<int> result;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

std::set<int> Task349::solve(const std::vector<int> &num1, const std::vector<int> &num2) const {
    std::vector<int> result = intersection(num1, num2);
    return {result.cbegin(), result.cend()};
}