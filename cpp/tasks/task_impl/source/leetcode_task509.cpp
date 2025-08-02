/**
  ******************************************************************************
  * @file           : leetcode_task509.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task509.h"

static int fib1(int n) {
    static std::vector<int> fibVec{0, 1};
    if (fibVec.size() <= n) {
        for (int i = fibVec.size(); i <= n; ++i) {
            fibVec.push_back(fibVec[i - 1] + fibVec[i - 2]);
        }
    }
    return fibVec[n];
}

static int fib2(int n) {
    if (n == 0) return 0;
    int dp_1 = 0, dp_2 = 1;
    for (int i = 2; i <= n; ++i) {
        int sum = dp_1 + dp_2;
        dp_1 = dp_2;
        dp_2 = sum;
    }
    return dp_2;
}

int LeetcodeTask509::solve(int n) const {
    return fib2(n);
}