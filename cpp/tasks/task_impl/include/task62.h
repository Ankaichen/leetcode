/**
  ******************************************************************************
  * @file           : task62.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK62_H
#define LEETCODE_TASK62_H

#include "../../core/task.hpp"

class Task62 : public Task<62, int(int, int)> {
public:
    Task62();

    ~Task62() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同路径";
    }

    [[nodiscard]] int solve(int m, int n) const override;
};

#endif //LEETCODE_TASK62_H
