/**
  ******************************************************************************
  * @file           : task2416.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-30
  ******************************************************************************
  */

#ifndef LEETCODE_TASK2416_H
#define LEETCODE_TASK2416_H

#include "../../core/task.hpp"

class Task2416 : public Task<2416, std::vector<int>(const std::vector<std::string> &)> {
public:
    Task2416();

    ~Task2416() noexcept override = default;

    std::string title() const override {
        return "字符串的前缀分数和";
    }

    std::vector<int> solve(const std::vector<std::basic_string<char>> &words) const override;
};

#endif //LEETCODE_TASK2416_H
