/**
  ******************************************************************************
  * @file           : task416.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK416_H
#define LEETCODE_TASK416_H

#include "../../core/task.hpp"

class Task416 : public Task<416, bool(const std::vector<int> &)> {
public:
    Task416();

    ~Task416() noexcept override = default;

    std::string title() const override {
        return "分割等和子集";
    }

    bool solve(const std::vector<int> &nums) const override;
};

#endif //LEETCODE_TASK416_H
