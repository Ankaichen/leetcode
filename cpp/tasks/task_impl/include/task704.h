/**
  ******************************************************************************
  * @file           : task704.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK704_H
#define LEETCODE_TASK704_H

#include "../../core/task.hpp"

class Task704 : public Task<704, int(const std::vector<int> &, int)> {
public:
    Task704();

    ~Task704() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "二分查找";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums, int target) const override;
};
#endif //LEETCODE_TASK704_H
