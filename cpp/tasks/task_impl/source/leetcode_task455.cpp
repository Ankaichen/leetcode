/**
  ******************************************************************************
  * @file           : leetcode_task455.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task455.h"

static int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    auto gb = g.cbegin(), sb = s.cbegin();
    int count = 0;
    while (gb != g.cend() && sb != s.cend()) {
        if (*gb <= *sb) {
            ++gb;
            ++sb;
            ++count;
        } else {
            ++sb;
        }
    }
    return count;
}

int LeetcodeTask455::solve(const std::vector<int> &g, const std::vector<int> &s) const {
    return findContentChildren(const_cast<std::vector<int>&>(g), const_cast<std::vector<int>&>(s));
}