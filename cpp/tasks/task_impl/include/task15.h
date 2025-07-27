/**
  ******************************************************************************
  * @file           : task15.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-25
  ******************************************************************************
  */

#ifndef LEETCODE_TASK15_H
#define LEETCODE_TASK15_H

#include "../../core/task.hpp"

class Task15 : public Task<15, std::multiset<std::multiset<int>>(const std::vector<int> &)> {
public:
    Task15();

    ~Task15() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "三数之和";
    }

    [[nodiscard]] std::multiset<std::multiset<int>> solve(const std::vector<int> &nums) const override;
};

#endif //LEETCODE_TASK15_H
