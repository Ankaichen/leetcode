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

std::ostringstream &KamacoderTask46::solve(std::istringstream &cin) const {
    CLEAR_STREAM(cout);
    return main1(cin);
}
