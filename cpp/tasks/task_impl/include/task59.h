/**
  ******************************************************************************
  * @file           : task59.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK59_H
#define LEETCODE_TASK59_H

#include "../../core/task.hpp"

class Task59 : public Task<59, std::vector<std::vector<int>>(int)> {
public:
    Task59();

    ~Task59() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "螺旋矩阵 II";
    }

    [[nodiscard]] std::vector<std::vector<int>> solve(int n) const override;
};

#endif //LEETCODE_TASK59_H
