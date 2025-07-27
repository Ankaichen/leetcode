/**
  ******************************************************************************
  * @file           : task130.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-1
  ******************************************************************************
  */

#ifndef LEETCODE_TASK130_H
#define LEETCODE_TASK130_H

#include "../../core/task.hpp"

class Task130 : public Task<130, std::vector<std::vector<char>>(const std::vector<std::vector<char>>&)> {
public:
    Task130();
    ~Task130() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "被围绕的区域";
    }
    [[nodiscard]] std::vector<std::vector<char>> solve(const std::vector<std::vector<char>> &board) const override;
};

#endif //LEETCODE_TASK130_H
