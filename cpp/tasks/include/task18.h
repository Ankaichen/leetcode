/**
  ******************************************************************************
  * @file           : task18.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-25
  ******************************************************************************
  */

#ifndef LEETCODE_TASK18_H
#define LEETCODE_TASK18_H

#include "../task.hpp"

class Task18 : public Task<18, std::multiset<std::multiset<int>>(const std::vector<int> &, int)> {
public:
    Task18();
    ~Task18() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "四数之和";
    }
    [[nodiscard]] std::multiset<std::multiset<int>> solve(const std::vector<int> &nums, int target) const override;
};

#endif //LEETCODE_TASK18_H
