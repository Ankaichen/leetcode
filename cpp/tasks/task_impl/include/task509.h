/**
  ******************************************************************************
  * @file           : task509.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK509_H
#define LEETCODE_TASK509_H

#include "../../core/task.hpp"

class Task509 : public Task<509, int(int)> {
public:
    Task509();
    ~Task509() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "斐波那契数";
    }
    [[nodiscard]] int solve(int n) const override;
};

#endif //LEETCODE_TASK509_H
