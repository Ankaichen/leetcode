/**
  ******************************************************************************
  * @file           : leetcode_task541.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task541.h"

static std::string reverseStr1(std::string &s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        std::reverse(s.begin() + i, i + k < s.size() ? s.begin() + i + k : s.end());
    }
    return s;
}

static std::string reverseStr2(std::string &s, int k) {
    for (int i = 0; i < s.size(); i += (2 * k)) {
        int end = i + k > s.size() ? static_cast<int>(s.size()) : i + k;
        for (int j = 0; j < (end - i) / 2; ++j) {
            std::swap(s[i + j], s[end - j - 1]);
        }
    }
    return s;
}

std::string LeetcodeTask541::solve(const std::string &s, int k) const {
    return reverseStr2(const_cast<std::string &>(s), k);
}