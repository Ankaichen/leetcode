/**
  ******************************************************************************
  * @file           : task209.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK209_H
#define LEETCODE_TASK209_H

#include "../../core/task.hpp"

class Task209 : public Task<209, int(int, const std::vector<int> &)> {
public:
    Task209();

    ~Task209() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "长度最小的子数组";
    }

    [[nodiscard]] int solve(int target, const std::vector<int> &nums) const override;
};

#endif //LEETCODE_TASK209_H
