/**
  ******************************************************************************
  * @file           : task40.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task40.h"

Task40::Task40() {
    this->addTestCase("candidates = [10,1,2,7,6,1,5]; target = 8", "{{1,1,6},{1,2,5},{1,7},{2,6}}");
    this->addTestCase("candidates = [2,5,2,1,2]; target = 5", "{{1,2,2},{5}}");
}

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

std::set<std::set<int>> Task40::solve(const std::vector<int> &candidates, int target) const {
    std::vector<std::vector<int>> result = combinationSum1(const_cast<std::vector<int> &>(candidates), target);
    std::set<std::set<int>> resSet;
    for (auto &v : result) {
        resSet.emplace(v.cbegin(), v.cend());
    }
    return resSet;
}