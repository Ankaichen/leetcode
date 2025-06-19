/**
  ******************************************************************************
  * @file           : task344.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task344.h"

Task344::Task344() {
    this->addTestCase("s = [h,e,l,l,o]", "[o,l,l,e,h]");
    this->addTestCase("s = [H,a,n,n,a,h]", "[h,a,n,n,a,H]");
}

static void reverseString1(std::vector<char>& s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        std::swap(s[i], s[s.size() - i - 1]);
    }
}

static void reverseString2(std::vector<char>& s) {
    std::reverse(s.begin(), s.end());
}

std::vector<char> Task344::solve(const std::vector<char> &s) const {
    std::vector<char> input(s.begin(), s.end());
    reverseString1(input);
    return input;
}