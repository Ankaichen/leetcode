/**
  ******************************************************************************
  * @file           : task1.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task1.h"

Task1::Task1() {
    this->addTestCase("nums = [2,7,11,15]; target = 9", "[0,1]");
    this->addTestCase("nums = [3,2,4]; target = 6", "[1,2]");
    this->addTestCase("nums = [3, 3]; target = 6", "[0,1]");
}

static std::vector<int> twoSum1(const std::vector<int> &nums, int target) {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

static std::vector<int> twoSum2(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        auto pair_i = map.find(nums[i]);
        if (pair_i != map.end()) {
            return {pair_i->second, i};
        } else {
            map.insert(std::make_pair(target - nums[i], i));
        }
    }
    return {-1, -1};
}

std::vector<int> Task1::solve(const std::vector<int> &nums, int target) const {
    return twoSum2(nums, target);
}
