/**
  ******************************************************************************
  * @file           : task416.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK416_HPP
#define LEETCODE_TASK416_HPP

#include "../task.hpp"

class Task416 : public Task<416, bool(const std::vector<int> &)> {
public:
    Task416();

    ~Task416() noexcept override = default;

    std::string title() const override {
        return "分割等和子集";
    }

    bool solve(const std::vector<int> &nums) const override;
};

Task416::Task416() {
    this->addTestCase("nums = [1,5,11,5]", "true");
    this->addTestCase("nums = [1,2,3,5]", "false");
}

bool canPartition1(const std::vector<int> &nums) {
    if (nums.size() <= 1) return false;
    int sum = 0;
    for (int i: nums) sum += i;
    if (sum % 2 == 1) return false;
    int n = sum / 2;
    std::vector<std::vector<int>> dp(nums.size() + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
            }
            if (dp[i][j] == n) {
                return true;
            }
        }
    }
    return false;
}

bool Task416::solve(const std::vector<int> &nums) const {
    return canPartition1(nums);
}

#endif //LEETCODE_TASK416_HPP
