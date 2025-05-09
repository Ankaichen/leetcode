/**
  ******************************************************************************
  * @file           : task77.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK77_HPP
#define LEETCODE_TASK77_HPP

#include "../task.hpp"

class Task77 : public Task<77, std::set<std::set<int>>(int, int)> {
public:
    Task77();
    ~Task77() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合";
    }
    [[nodiscard]] std::set<std::set<int>> solve(int n, int k) const override;

    void backtracking(int n, int k, int startIndex);

    std::vector<std::vector<int>> result;
    std::vector<int> path;
};

Task77::Task77() {
    this->addTestCase("n = 4; k = 2", "{{2,4}, {3,4}, {2,3}, {1,2}, {1,3}, {1,4}}");
    this->addTestCase("n = 1; k = 1", "{{1}}");
}

void Task77::backtracking(int n, int k, int startIndex) {
    if (path.size() >= k) {
        result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
        path.push_back(i);
        backtracking(n, k, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> combine(int n, int k) {
    Task77 t;
    t.result.clear();
    t.path.clear();
    t.backtracking(n, k, 1);
    return t.result;
}

std::set<std::set<int>> Task77::solve(int n, int k) const {
    std::vector<std::vector<int>> res_vec = combine(n, k);
    std::set<std::set<int>> res_set{};
    for (const auto v : res_vec) {
        std::set<int> tempSet{v.begin(), v.end()};
        res_set.insert(tempSet);
    }
    return res_set;
}

#endif //LEETCODE_TASK77_HPP
