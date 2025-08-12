/**
 ******************************************************************************
 * @file           : leetcode_task46.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-12
 ******************************************************************************
 */

#include "../include/leetcode_task46.h"

static std::vector<std::vector<int>> permute1(std::vector<int> &nums) {
    // 回溯法
    if (nums.empty()) return {};
    std::vector<std::vector<int>> results{};
    auto backtracking = [&results, &nums](auto &self, int start) -> void {
        if (start >= nums.size()) {
            results.emplace_back(nums.begin(), nums.end());
            return;
        }
        self(self, start + 1);
        for (int i = start + 1; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);
            self(self, start + 1);
            std::swap(nums[start], nums[i]);
        }
    };
    backtracking(backtracking, 0);
    return results;
}

std::vector<std::vector<int>> LeetcodeTask46::solve(const std::vector<int> &nums) const { return permute1(const_cast<std::vector<int> &>(nums)); }