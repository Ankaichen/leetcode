/**
  ******************************************************************************
  * @file           : task344.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-26
  ******************************************************************************
  */

#ifndef LEETCODE_TASK344_H
#define LEETCODE_TASK344_H

#include "../../core/task.hpp"

class Task344 : public Task<344, std::vector<char>(const std::vector<char>&)> {
public:
    Task344();
    ~Task344() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "反转字符串";
    }
    [[nodiscard]] std::vector<char> solve(const std::vector<char> &s) const override;
};

#endif //LEETCODE_TASK344_H
