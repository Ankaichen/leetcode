/**
  ******************************************************************************
  * @file           : leetcode_task344.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task344.h"

static void reverseString1(std::vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        std::swap(s[i], s[s.size() - i - 1]);
    }
}

static void reverseString2(std::vector<char>& s) {
    std::reverse(s.begin(), s.end());
}

std::vector<char> LeetcodeTask344::solve(const std::vector<char> &s) const {
    std::vector<char> input(s.begin(), s.end());
    reverseString1(input);
    return input;
}