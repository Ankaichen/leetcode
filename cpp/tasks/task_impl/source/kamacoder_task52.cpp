/**
 ******************************************************************************
 * @file           : kamacoder_task52.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-9-20
 ******************************************************************************
 */

#include "../include/kamacoder_task52.h"

static std::ostringstream cout;

static std::ostringstream &main1(std::istringstream &cin) {
    // 完全背包问题 动态规划
    int n, v;
    cin >> n >> v;
    std::vector<int> weights(n, -1), values(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    std::vector<std::vector<int>> dp(v + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= v; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (i >= weights[j - 1]) { // 与01背包问题的区别 此处减去weights[j - 1]后也需要考虑[j]的dp
                dp[i][j] = std::max(dp[i][j], dp[i - weights[j - 1]][j] + values[j - 1]);
            }
        }
    }
    cout << dp[v][n] << std::endl;
    return cout;
}

static std::ostringstream &main2(std::istringstream &cin) {
    // 1维dp数组
    int n, v;
    cin >> n >> v;
    std::vector<int> weights(n, -1), values(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    std::vector<int> dp(v + 1, 0);
    for (int i = 1; i <= v; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= weights[j - 1]) { // 与01背包问题的区别 此处减去weights[j - 1]后也需要考虑[j]的dp
                dp[i] = std::max(dp[i], dp[i - weights[j - 1]] + values[j - 1]);
            }
        }
    }
    cout << dp[v] << std::endl;
    return cout;
}

std::ostringstream &KamacoderTask52::solve(std::istringstream &cin) const {
    CLEAR_STREAM(cout);
    return main2(cin);
}
