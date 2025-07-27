/**
  ******************************************************************************
  * @file           : task40.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK40_H
#define LEETCODE_TASK40_H

#include "../../core/task.hpp"

class Task40 : public Task<40, std::set<std::set<int>>(const std::vector<int> &, int)> {
public:
    Task40();
    ~Task40() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合总和 II";
    }
    [[nodiscard]] std::set<std::set<int>> solve(const std::vector<int> &candidates, int target) const override;
};

#endif //LEETCODE_TASK40_H
