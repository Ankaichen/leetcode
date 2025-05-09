/**
  ******************************************************************************
  * @file           : task216.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK216_HPP
#define LEETCODE_TASK216_HPP

#include "../task.hpp"

class Task216 : public Task<216, std::set<std::set<int>>(int, int)> {
public:
    Task216();
    ~Task216() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合总和 III";
    }
    [[nodiscard]] std::set<std::set<int>> solve(int k, int n) const override;

    void backtracking(int k, int n, int startIndex);

    std::vector<std::vector<int>> result;
    std::vector<int> path;
};

Task216::Task216() {
    this->addTestCase("k = 3; n = 7", "{{1,2,4}}");
    this->addTestCase("k = 3; n = 9", "{{1,2,6}, {1,3,5}, {2,3,4}}");
    this->addTestCase("k = 4; n = 1", "{}");
}

void Task216::backtracking(int k, int n, int startIndex) {
    if (n <= 0 && path.size() < k) return;
    if (path.size() == k) {
        if (n == 0) result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {
        path.push_back(i);
        this->backtracking(k, n - i, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum3(int k, int n) {
    Task216 t;
    t.result.clear();
    t.path.clear();
    t.backtracking(k, n, 1);
    return t.result;
}

std::set<std::set<int>> Task216::solve(int k, int n) const {
    std::vector<std::vector<int>> res_vec = combinationSum3(k, n);
    std::set<std::set<int>> res_set{};
    for (const auto v : res_vec) {
        std::set<int> tempSet{v.begin(), v.end()};
        res_set.insert(tempSet);
    }
    return res_set;
}

#endif //LEETCODE_TASK216_HPP
