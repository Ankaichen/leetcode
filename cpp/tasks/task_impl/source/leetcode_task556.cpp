/**
  ******************************************************************************
  * @file           : leetcode_task556.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task556.h"

static int nextGreaterElement1(int n) {
    if (n < 10) return -1;
    std::string s = std::to_string(n);
    int i = s.size() - 2;
    for (; i >= 0 && s[i] >= s[i + 1]; --i);
    if (i >= 0) {
        int j = s.size() - 1;
        for (; j > i && s[j] <= s[i]; --j);
        std::swap(s[i], s[j]);
        std::reverse(s.begin() + 1 + i, s.end());
        long res = std::stol(s);
        return res > 0x7fffffff ? -1 : res;
    } else {
        return -1;
    }
}

int LeetcodeTask556::solve(int n) const {
    return nextGreaterElement1(n);
}