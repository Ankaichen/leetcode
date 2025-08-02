/**
  ******************************************************************************
  * @file           : leetcode_task202.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task202.h"

static bool isHappy(int n) {
    std::unordered_set<int> set{n};
    while (true) {
        int sum = 0;
        for (int temp_n = n; temp_n != 0; temp_n /= 10) {
            int single_n = temp_n % 10;
            sum += (single_n * single_n);
        }
        if (sum == 1) {
            return true;
        } else if (set.find(sum) != set.end()) {
            return false;
        } else {
            set.insert(sum);
            n = sum;
        }
    }
}

bool LeetcodeTask202::solve(int n) const {
    return isHappy(n);
}