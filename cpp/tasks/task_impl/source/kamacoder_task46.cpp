/**
 ******************************************************************************
 * @file           : kamacoder_task46.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-3
 ******************************************************************************
 */

#include "../include/kamacoder_task46.h"

#include <vector>

static std::ostringstream cout;

static std::ostringstream &main1(std::istringstream &cin) {
    int M, N;
    cin >> M >> N;
    std::vector<int> valume(M, 0), value(M, 0);
    for (int i = 0; i < M; ++i) cin >> valume[i];
    for (int i = 0; i < M; ++i) cin >> value[i];
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0));
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= valume[i - 1]) {
                dp[i][j] = std::max(dp[i - 1][j - valume[i - 1]] + value[i - 1], dp[i][j]);
            }
        }
    }
    cout << dp[M][N];
    return cout;
}

static std::ostringstream &main2(std::istringstream &cin) {
    // 0/1背包问题 动态规划
    // dp[i][j] 表示只考虑前i个物品 拥有j个空间时 最大价值
    // 考虑每个物品时(总空间足够放入该物品的前提下) 有两种情况: 放入该物品 不放入该物品
    // 放入该物品: dp[i][j] = dp[i - 1][j - space[i]] + value[i] 即不放入该物品且去除该物品所占空间后的价值 加 该物品的价值
    // 不放入该物品: dp[i][j] = dp[i - 1][j] 即 空间不变 考虑物品减一
    int M, N;
    cin >> M >> N;
    std::vector<int> space(M, 0), value(M, 0);
    for (int i = 0, temp; i < M && cin >> temp; ++i) space[i] = temp;
    for (int i = 0, temp; i < M && cin >> temp; ++i) value[i] = temp;
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, 0));
    int result = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i - 1][j];                                                                                   // 首先初始化 默认不放入
            if (j >= space[i - 1]) {                                                                                   // 可以放下当前物品
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - space[i - 1]] + value[i - 1] /* 放下当前物品后的价值 */);  // 取最大值
            }
            result = std::max(dp[i][j], result);
        }
    }
    cout << result << std::endl;
    return cout;
}

static std::ostringstream &main3(std::istringstream &cin) {
    // 0/1背包问题 动态规划 一维dp数组
    // 由于每次只需要dp[i-1]中的数据 并且j - space[i]一定小于j 所以反向变量j 则dp数组可以覆盖
    int M, N;
    cin >> M >> N;
    std::vector<int> space(M, 0), value(M, 0);
    for (int i = 0, temp; i < M && cin >> temp; ++i) space[i] = temp;
    for (int i = 0, temp; i < M && cin >> temp; ++i) value[i] = temp;
    std::vector<int> dp(N + 1, 0);
    int result = 0;
    for (int i = 1; i <= M; ++i) {
        for (int j = N; j >= 1; --j) {
            if (j >= space[i - 1]) {                                                                      // 可以放下当前物品
                dp[j] = std::max(dp[j], dp[j - space[i - 1]] + value[i - 1] /* 放下当前物品后的价值 */);  // 取最大值
            }
            result = std::max(dp[j], result);
        }
    }
    cout << result << std::endl;
    return cout;
}

std::ostringstream &KamacoderTask46::solve(std::istringstream &cin) const {
    CLEAR_STREAM(cout);
    return main3(cin);
}
