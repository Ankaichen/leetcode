/**
  ******************************************************************************
  * @file           : task27.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK27_H
#define LEETCODE_TASK27_H

#include "../task.hpp"

class Task27 : public Task<27, int(const std::vector<int> &, int)> {
public:
    Task27();

    ~Task27() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "移除元素";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums, int val) const override;
};

#endif //LEETCODE_TASK27_H
