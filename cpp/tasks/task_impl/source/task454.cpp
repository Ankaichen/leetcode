/**
  ******************************************************************************
  * @file           : task454.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task454.h"

Task454::Task454() {
    this->addTestCase("nums1 = [1,2]; nums2 = [-2,-1]; nums3 = [-1,2]; nums4 = [0,2]", "2");
    this->addTestCase("nums1 = [0]; nums2 = [0]; nums3 = [0]; nums4 = [0]", "1");
    this->addTestCase("nums1 = [-1,-1]; nums2 = [-1,1]; nums3 = [-1,1]; nums4 = [1,-1]", "6");
}

static int fourSumCount(const std::vector<int> &nums1, const std::vector<int> &nums2, const std::vector<int> &nums3,
                 const std::vector<int> &nums4) {
    std::unordered_map<int, int> map;
    int result = 0;
    for (const auto &n1: nums1) {
        for (const auto &n2: nums2) {
            auto iter = map.find(-n1 - n2);
            if (iter != map.end()) {
                ++iter->second;
            } else {
                map.insert(std::make_pair(-n1 - n2, 1));
            }
        }
    }
    for (const auto &n3: nums3) {
        for (const auto &n4: nums4) {
            auto iter = map.find(n3 + n4);
            if (iter != map.end()) result += iter->second;
        }
    }
    return result;
}

int Task454::solve(const std::vector<int> &nums1, const std::vector<int> &nums2, const std::vector<int> &nums3,
                   const std::vector<int> &nums4) const {
    return fourSumCount(nums1, nums2, nums3, nums4);
}