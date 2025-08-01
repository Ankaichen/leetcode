/**
  ******************************************************************************
  * @file           : task3.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task3.h"

static int lengthOfLongestSubstring1(std::string s) {
    if (s.empty()) return 0;
    std::unordered_set<char> set;
    int left = 0, right = 1;
    int length = 1;
    set.insert(s[0]);
    for (;right < s.size();) {
        auto iter = set.find(s[right]);
        if (iter == set.end()) {
            length = std::max(length, right - left + 1);
            set.insert(s[right++]);
        } else {
            for (;s[left] != s[right]; ++left) {
                set.erase(s[left]);
            }
            ++left;
            ++right;
        }
    }
    return length;
}

int LeetcodeTask3::solve(const std::string &s) const {
    return lengthOfLongestSubstring1(s);
}