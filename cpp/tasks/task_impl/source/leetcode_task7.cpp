/**
  ******************************************************************************
  * @file           : task7.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task7.h"

static int reverse1(int x) {
    if (x <= INT_MIN) return 0;
    int res = 0;
    bool flag = x < 0;
    x = std::abs(x);
    while (x > 0) {
        if (res != 0 && 0x7fffffff / res < 10) {
            return 0;
        } else {
            res *= 10;
        }
        int i = x % 10;
        if ((0x7fffffff - res) < i) {
            return 0;
        } else {
            res += i;
        }
        x = x / 10;
    }
    return flag ? -res : res;
}

static int reverse2(int x) {
    int res = 0;
    while (x != 0) {
        if (res < INT_MIN / 10 || res > INT_MAX / 10) {
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int LeetcodeTask7::solve(int x) const {
    return reverse2(x);
}