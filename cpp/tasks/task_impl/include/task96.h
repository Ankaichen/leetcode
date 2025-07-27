/**
  ******************************************************************************
  * @file           : task96.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK96_H
#define LEETCODE_TASK96_H

#include "../../core/task.hpp"

class Task96 : public Task<96, int(int)> {
public:
    Task96();

    ~Task96() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "不同的二叉搜索树";
    }

    [[nodiscard]] int solve(int n) const override;
};

#endif //LEETCODE_TASK96_H
