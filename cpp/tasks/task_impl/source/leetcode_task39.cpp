/**
  ******************************************************************************
  * @file           : leetcode_task39.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task39.h"

static void backtracking1(int index, const std::vector<int>& candidates, int target, std::vector<int> &comb, std::vector<std::vector<int>> &result) {
    if (target == 0) {
        result.emplace_back(comb.cbegin(), comb.cend());
    }
    if (target <= 0) {
        return;
    }
    for (int i = index; i < candidates.size(); ++i) {
        comb.push_back(candidates[i]);
        backtracking1(i, candidates, target - candidates[i], comb, result);
        comb.pop_back();
    }
}

static std::vector<std::vector<int>> combinationSum1(const std::vector<int>& candidates, int target) {
    std::vector<int> comb;
    std::vector<std::vector<int>> result;
    backtracking1(0, candidates, target, comb, result);
    return result;
}

static void backtracking2(int index, const std::vector<int>& candidates, int target, std::vector<int> &comb, std::vector<std::vector<int>> &result) {
    if (target == 0) {
        result.emplace_back(comb.cbegin(), comb.cend());
    }
    if (target <= 0) {
        return;
    }
    for (int i = index; i < candidates.size() && target >= candidates[i]; ++i) {
        comb.push_back(candidates[i]);
        backtracking2(i, candidates, target - candidates[i], comb, result);
        comb.pop_back();
    }
}

static std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    std::vector<int> comb;
    std::vector<std::vector<int>> result;
    std::sort(candidates.begin(), candidates.end());
    backtracking2(0, candidates, target, comb, result);
    return result;
}

std::vector<std::vector<int>> LeetcodeTask39::solve(const std::vector<int> &candidates, int target) const {
    return combinationSum2(const_cast<std::vector<int> &>(candidates), target);
}