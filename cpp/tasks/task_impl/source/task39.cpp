/**
  ******************************************************************************
  * @file           : task39.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task39.h"

Task39::Task39() {
    this->addTestCase("candidates = [2,3,6,7]; target = 7", "{{2,2,3},{7}}");
    this->addTestCase("candidates = [2,3,5]; target = 8", "{{2,2,2,2},{2,3,3},{3,5}}");
    this->addTestCase("candidates = [2]; target = 1", "{}");
}

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

std::set<std::set<int>> Task39::solve(const std::vector<int> &candidates, int target) const {
    std::vector<std::vector<int>> result = combinationSum2(const_cast<std::vector<int> &>(candidates), target);
    std::set<std::set<int>> resSet;
    for (auto &v : result) {
        resSet.emplace(v.cbegin(), v.cend());
    }
    return resSet;
}