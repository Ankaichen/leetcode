/**
  ******************************************************************************
  * @file           : task746.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-9
  ******************************************************************************
  */

#ifndef LEETCODE_TASK746_H
#define LEETCODE_TASK746_H

#include "../task.hpp"

class Task746 : public Task<746, int(const std::vector<int> &)> {
public:
    Task746();

    ~Task746() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "使用最小花费爬楼梯";
    }

    [[nodiscard]] int solve(const std::vector<int> &cost) const override;
};

#endif //LEETCODE_TASK746_H
