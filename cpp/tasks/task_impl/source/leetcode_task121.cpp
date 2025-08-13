/**
 ******************************************************************************
 * @file           : leetcode_task121.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-13
 ******************************************************************************
 */

#include "../include/leetcode_task121.h"

static int maxProfit1(std::vector<int>& prices) {
    int buyPrice = prices[0], result = 0;
    for (int i = 1; i < prices.size(); ++i) {
        result = std::max(prices[i] - buyPrice, result);
        buyPrice = std::min(buyPrice, prices[i]);
    }
    return result;
}

int LeetcodeTask121::solve(const std::vector<int>& prices) const { return maxProfit1(const_cast<std::vector<int>&>(prices)); }
