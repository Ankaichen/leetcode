/**
  ******************************************************************************
  * @file           : task216.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task216.h"


static std::vector<std::vector<int>> result;
static std::vector<int> path;

Task216::Task216() {
    this->addTestCase("k = 3; n = 7", "{{1,2,4}}");
    this->addTestCase("k = 3; n = 9", "{{1,2,6}, {1,3,5}, {2,3,4}}");
    this->addTestCase("k = 4; n = 1", "{}");
}

static void backtracking(int k, int n, int startIndex) {
    if (n <= 0 && path.size() < k) return;
    if (path.size() == k) {
        if (n == 0) result.push_back(path);
        return;
    }
    for (int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i) {
        path.push_back(i);
        backtracking(k, n - i, i + 1);
        path.pop_back();
    }
}

static std::vector<std::vector<int>> combinationSum3(int k, int n) {
    result.clear();
    path.clear();
    backtracking(k, n, 1);
    return result;
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