/**
  ******************************************************************************
  * @file           : leetcode_task77.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task77.h"

static std::vector<std::vector<int>> result;
static std::vector<int> path;

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

std::vector<std::vector<int>> LeetcodeTask77::solve(int n, int k) const {
    return combine(n, k);
}