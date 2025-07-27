/**
  ******************************************************************************
  * @file           : task151.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-11
  ******************************************************************************
  */

#ifndef LEETCODE_TASK151_H
#define LEETCODE_TASK151_H

#include "../../core/task.hpp"

class Task151 : public Task<151, std::string(const std::string &)> {
public:
    Task151();

    ~Task151() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "反转字符串中的单词";
    }

    [[nodiscard]] std::string solve(const std::string &s) const override;
};

#endif //LEETCODE_TASK151_H
