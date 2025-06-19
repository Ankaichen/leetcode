/**
  ******************************************************************************
  * @file           : task96.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task96.h"

Task96::Task96() {
    this->addTestCase("n = 3", "5");
    this->addTestCase("n = 1", "1");
}

static int numTrees1(int n) {
    if (n < 3)
        return n;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        int count = 0;
        for (int j = 0; j <= i - 1; ++j) {
            count += dp[j] * dp[i - j - 1];
        }
        dp[i] = count;
    }
    return dp[n];
}

int Task96::solve(int n) const {
    return numTrees1(n);
}