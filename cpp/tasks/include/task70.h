/**
  ******************************************************************************
  * @file           : task70.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK70_H
#define LEETCODE_TASK70_H

#include "../task.hpp"

class Task70 : public Task<70, int(int)> {
public:
    Task70();
    ~Task70() noexcept override = default;
    std::string title() const override {
        return "爬楼梯";
    }
    int solve(int n) const override;
};

#endif //LEETCODE_TASK70_H
