/**
  ******************************************************************************
  * @file           : task31.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-29
  ******************************************************************************
  */

#ifndef LEETCODE_TASK31_H
#define LEETCODE_TASK31_H

#include "../../core/task.hpp"

class Task31 : public Task<31, std::vector<int>(const std::vector<int>&)> {
public:
    Task31();
    ~Task31() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "下一个排列";
    }
    [[nodiscard]] std::vector<int> solve(const std::vector<int> &nums) const override;
};

#endif //LEETCODE_TASK31_H
