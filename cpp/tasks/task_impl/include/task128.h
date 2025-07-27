/**
  ******************************************************************************
  * @file           : task128.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-30
  ******************************************************************************
  */

#ifndef LEETCODE_TASK128_H
#define LEETCODE_TASK128_H

#include "../../core/task.hpp"

class Task128 : public Task<128, int(const std::vector<int> &)> {
public:
    Task128();

    ~Task128() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "最长连续序列";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums) const override;
};
#endif //LEETCODE_TASK128_H
