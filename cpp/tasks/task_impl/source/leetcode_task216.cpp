/**
  ******************************************************************************
  * @file           : leetcode_task216.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task216.h"


static std::vector<std::vector<int>> result;
static std::vector<int> path;


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

std::vector<std::vector<int>> LeetcodeTask216::solve(int k, int n) const {
    return combinationSum3(k, n);
}