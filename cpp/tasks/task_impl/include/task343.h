/**
  ******************************************************************************
  * @file           : task343.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK343_H
#define LEETCODE_TASK343_H

#include "../../core/task.hpp"

class Task343 : public Task<343, int(int)> {
public:
    Task343();

    ~Task343() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "整数拆分";
    }

    [[nodiscard]] int solve(int n) const override;
};

#endif //LEETCODE_TASK343_H
