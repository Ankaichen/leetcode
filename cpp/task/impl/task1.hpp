/**
  ******************************************************************************
  * @file           : task1.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-18
  ******************************************************************************
  */

#ifndef LEETCODE_TASK1_HPP
#define LEETCODE_TASK1_HPP

#include <vector>

#include "../task.hpp"

class Task1 : public Task<1, std::vector<int>(const std::vector<int> &, int)> {
public:
    Task1();

    ~Task1() noexcept override = default;

    [[nodiscard]] std::string title() const override  {
        return "两数之和";
    }

    [[nodiscard]] std::vector<int> solve(const std::vector<int> &nums, int target) const override;
};

Task1::Task1() {
    this->addTestCase("nums = [2,7,11,15]; target = 9", "[0,1]");
    this->addTestCase("nums = [3,2,4]; target = 6", "[1,2]");
    this->addTestCase("nums = [3, 3]; target = 6", "[0,1]");
    this->addTestCase("nums = [3, 3]; target = 6", "[1]");
}

std::vector<int> Task1::solve(const std::vector<int> &nums, int target) const {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

#endif //LEETCODE_TASK1_HPP
