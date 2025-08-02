/**
  ******************************************************************************
  * @file           : leetcode_task128.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task128.h"

static int longestConsecutive1(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (int i: nums) {
        set.insert(i);
    }
    int maxContinue = 0;
    for (int i: set) {
        if (set.find(i - 1) != set.end())
            continue;
        int curContinue = 1;
        int curNum = i;
        while (set.find(curNum + 1) != set.end()) {
            ++curContinue;
            ++curNum;
        }
        maxContinue = std::max(maxContinue, curContinue);
    }
    return maxContinue;
}

static int longestConsecutive2(const std::vector<int>& nums) {
    UnionFind<int> uf;
    for (int i : nums) {
        uf.insert(i);
    }
    for (int i : nums) {
        uf.union_value(i, i + 1);
    }
    int result = 0;
    for (int i : nums) {
        result = std::max(static_cast<int>(uf.union_size(i)), result);
    }
    return result;
}

int LeetcodeTask128::solve(const std::vector<int> &nums) const {
    return longestConsecutive2(nums);
}
