/**
 ******************************************************************************
 * @file           : leetcode_task96.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-6-19
 ******************************************************************************
 */

#include "../include/leetcode_task96.h"

static int numTrees1(int n) {
    // 动态规划 dp[i]表示n=i时的结果
    std::vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;                            // 初始化为0 计算总和
        for (int j = 1; j <= i; ++j) {        // j表示根节点
            int left = j - 1, right = i - j;  // 计算根节点左右子树的节点数量
            dp[i] += dp[left] * dp[right];    // 根据dp数组中保存的子树结果计算当前结果 将所有可能的根节点情况相加
        }
    }
    return dp[n];
}

int LeetcodeTask96::solve(int n) const { return numTrees1(n); }