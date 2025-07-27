/**
  ******************************************************************************
  * @file           : task77.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task77.h"

static std::vector<std::vector<int>> result;
static std::vector<int> path;

Task77::Task77() {
    this->addTestCase("n = 4; k = 2", "{{2,4}, {3,4}, {2,3}, {1,2}, {1,3}, {1,4}}");
    this->addTestCase("n = 1; k = 1", "{{1}}");
}

static void backtracking(int n, int k, int startIndex) {
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

static std::vector<std::vector<int>> combine(int n, int k) {
    result.clear();
    path.clear();
    backtracking(n, k, 1);
    return result;
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