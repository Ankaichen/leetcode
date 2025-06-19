/**
  ******************************************************************************
  * @file           : task216.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK216_H
#define LEETCODE_TASK216_H

#include "../task.hpp"

class Task216 : public Task<216, std::set<std::set<int>>(int, int)> {
public:
    Task216();
    ~Task216() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合总和 III";
    }
    [[nodiscard]] std::set<std::set<int>> solve(int k, int n) const override;
};

#endif //LEETCODE_TASK216_H
