/**
  ******************************************************************************
  * @file           : task1.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-18
  ******************************************************************************
  */

#ifndef LEETCODE_TASK1_H
#define LEETCODE_TASK1_H

#include "../task.hpp"

class Task1 : public Task<1, std::vector<int>(const std::vector<int> &, int)> {
public:
    Task1();

    ~Task1() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两数之和";
    }

    [[nodiscard]] std::vector<int> solve(const std::vector<int> &nums, int target) const override;
};

#endif //LEETCODE_TASK1_H
