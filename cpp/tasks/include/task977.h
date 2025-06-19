/**
  ******************************************************************************
  * @file           : task977.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK977_H
#define LEETCODE_TASK977_H

#include "../task.hpp"

class Task977 : public Task<977, std::vector<int>(const std::vector<int> &)> {
public:
    Task977();

    ~Task977() noexcept override = default;

    std::string title() const override {
        return "有序数组的平方";
    }

    std::vector<int> solve(const std::vector<int> &nums) const override;
};

#endif //LEETCODE_TASK977_H
