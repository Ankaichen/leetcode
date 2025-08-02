/**
  ******************************************************************************
  * @file           : leetcode_task40.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task40.h"

static void backtracking1(int index, const std::vector<int>& candidates, int target, std::vector<int> &comb, std::vector<std::vector<int>> &result) {
    if (target == 0) {
        result.emplace_back(comb.cbegin(), comb.cend());
    }
    if (target <= 0) {
        return;
    }
    for (int i = index; i < candidates.size() && target >= candidates[i]; ++i) {
        // 同一层相同的剪枝
        if (i >= 1 && i - 1 >= index && candidates[i] == candidates[i - 1]) continue;
        comb.push_back(candidates[i]);
        backtracking1(i + 1, candidates, target - candidates[i], comb, result);
        comb.pop_back();
    }
}

static std::vector<std::vector<int>> combinationSum1(std::vector<int>& candidates, int target) {
    std::vector<int> comb;
    std::vector<std::vector<int>> result;
    std::sort(candidates.begin(), candidates.end());
    backtracking1(0, candidates, target, comb, result);
    return result;
}

std::vector<std::vector<int>> LeetcodeTask40::solve(const std::vector<int> &candidates, int target) const {
    return combinationSum1(const_cast<std::vector<int> &>(candidates), target);
}