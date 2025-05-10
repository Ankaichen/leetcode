/**
  ******************************************************************************
  * @file           : task40.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK40_HPP
#define LEETCODE_TASK40_HPP

#include "../task.hpp"

class Task40 : public Task<40, std::set<std::set<int>>(const std::vector<int> &, int)> {
public:
    Task40();
    ~Task40() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合总和 II";
    }
    [[nodiscard]] std::set<std::set<int>> solve(const std::vector<int> &candidates, int target) const override;
};

Task40::Task40() {
    this->addTestCase("candidates = [10,1,2,7,6,1,5]; target = 8", "{{1,1,6},{1,2,5},{1,7},{2,6}}");
    this->addTestCase("candidates = [2,5,2,1,2]; target = 5", "{{1,2,2},{5}}");
}

void backtracking_Task40_1(int index, const std::vector<int>& candidates, int target, std::vector<int> &comb, std::vector<std::vector<int>> &result) {
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
        backtracking_Task40_1(i + 1, candidates, target - candidates[i], comb, result);
        comb.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum_Task40_1(std::vector<int>& candidates, int target) {
    std::vector<int> comb;
    std::vector<std::vector<int>> result;
    std::sort(candidates.begin(), candidates.end());
    backtracking_Task40_1(0, candidates, target, comb, result);
    return result;
}

std::set<std::set<int>> Task40::solve(const std::vector<int> &candidates, int target) const {
    std::vector<std::vector<int>> result = combinationSum_Task40_1(const_cast<std::vector<int> &>(candidates), target);
    std::set<std::set<int>> resSet;
    for (auto &v : result) {
        resSet.emplace(v.cbegin(), v.cend());
    }
    return resSet;
}

#endif //LEETCODE_TASK40_HPP
