/**
  ******************************************************************************
  * @file           : task39.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK39_H
#define LEETCODE_TASK39_H

#include "../task.hpp"

class Task39 : public Task<39, std::set<std::set<int>>(const std::vector<int> &, int)> {
public:
    Task39();
    ~Task39() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "组合总和";
    }
    [[nodiscard]] std::set<std::set<int>> solve(const std::vector<int> &candidates, int target) const override;
};

#endif //LEETCODE_TASK39_H
