/**
  ******************************************************************************
  * @file           : task202.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK202_H
#define LEETCODE_TASK202_H

#include "../../core/task.hpp"

class Task202 : public Task<202, bool(int)> {
public:
    Task202();

    ~Task202() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "快乐数";
    }

    [[nodiscard]] bool solve(int n) const override;
};

#endif //LEETCODE_TASK202_H
