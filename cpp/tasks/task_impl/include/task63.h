/**
  ******************************************************************************
  * @file           : task63.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK63_H
#define LEETCODE_TASK63_H

#include "../../core/task.hpp"

class Task63 : public Task<63, int(const std::vector<std::vector<int>> &)> {
public:
    Task63();

    ~Task63() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同路径 II";
    }

    [[nodiscard]] int solve(const std::vector<std::vector<int>> &obstacleGrid) const override;
};

#endif //LEETCODE_TASK63_H
