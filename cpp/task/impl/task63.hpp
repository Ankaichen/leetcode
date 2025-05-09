/**
  ******************************************************************************
  * @file           : task63.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK63_HPP
#define LEETCODE_TASK63_HPP

#include "../task.hpp"

class Task63 : public Task<63, int(const std::vector<std::vector<int>> &)> {
public:
    Task63();

    ~Task63() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同路径 II";
    }

    [[nodiscard]] int solve(const std::vector<std::vector<int>> &obstacleGrid) const override;
};

Task63::Task63() {
    this->addTestCase("obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]", "2");
    this->addTestCase("obstacleGrid = [[0,1],[0,0]]", "1");
}

int uniquePathsWithObstacles1(const std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1] == 1) continue;
            int count1 = i - 2 >= 0 && obstacleGrid[i - 2][j - 1] == 1 ? 0 : dp[i - 1][j];
            int count2 = j - 2 >= 0 && obstacleGrid[i - 1][j - 2] == 1 ? 0 : dp[i][j - 1];
            dp[i][j] = count1 + count2;
        }
    }
    return dp[m][n];
}

int uniquePathsWithObstacles2(const std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (obstacleGrid[i - 1][j - 1] == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

int Task63::solve(const std::vector<std::vector<int>> &obstacleGrid) const {
    return uniquePathsWithObstacles2(obstacleGrid);
}

#endif //LEETCODE_TASK63_HPP
