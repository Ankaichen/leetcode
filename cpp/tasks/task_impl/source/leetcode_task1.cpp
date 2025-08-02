/**
 ******************************************************************************
 * @file           : leetcode_task1.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-6-19
 ******************************************************************************
 */

#include "../include/leetcode_task1.h"

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

std::vector<int> LeetcodeTask1::solve(const std::vector<int> &nums, int target) const { return twoSum2(nums, target); }
