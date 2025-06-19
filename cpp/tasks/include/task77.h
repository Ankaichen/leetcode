/**
  ******************************************************************************
  * @file           : task77.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK77_H
#define LEETCODE_TASK77_H

#include "../task.hpp"

class Task77 : public Task<77, std::set<std::set<int>>(int, int)> {
public:
    Task77();
    ~Task77() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合";
    }
    [[nodiscard]] std::set<std::set<int>> solve(int n, int k) const override;
};

#endif //LEETCODE_TASK77_H
