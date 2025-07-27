/**
  ******************************************************************************
  * @file           : task556.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-29
  ******************************************************************************
  */

#ifndef LEETCODE_TASK556_H
#define LEETCODE_TASK556_H

#include "../../core/task.hpp"

class Task556 : public Task<556, int(int)> {
public:
    Task556();

    ~Task556() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "下一个更大元素 III";
    }

    [[nodiscard]] int solve(int n) const override;
};

#endif //LEETCODE_TASK556_H
