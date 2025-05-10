/**
  ******************************************************************************
  * @file           : task1049.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK1049_HPP
#define LEETCODE_TASK1049_HPP

#include "../task.hpp"

class Task1049 : public Task<1049, int(const std::vector<int> &)> {
public:
    Task1049();

    ~Task1049() noexcept override = default;

    std::string title() const override {
        return "最后一块石头的重量 II";
    }

    int solve(const std::vector<int> &stones) const override;
};

Task1049::Task1049() {
    this->addTestCase("stones = [2,7,4,1,8,1]", "1");
    this->addTestCase("stones = [31,26,33,21,40]", "5");
}

int lastStoneWeightII1(const std::vector<int> &stones) {
    int sum = 0;
    for (int i: stones) sum += i;
    int n = sum / 2;
    std::vector<std::vector<int>> dp(stones.size() + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= stones.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= stones[i - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
            }
        }
    }
    return sum - 2 * dp[stones.size()][n];
}

int Task1049::solve(const std::vector<int> &stones) const {
    return lastStoneWeightII1(stones);
}

#endif //LEETCODE_TASK1049_HPP
