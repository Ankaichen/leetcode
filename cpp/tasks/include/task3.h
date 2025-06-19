/**
  ******************************************************************************
  * @file           : task3.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK3_H
#define LEETCODE_TASK3_H

#include "../task.hpp"

class Task3 : public Task<3, int(const std::string &)> {
public:
    Task3();

    ~Task3() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "无重复字符的最长子串";
    }

    [[nodiscard]] int solve(const std::string &s) const override;
};

#endif //LEETCODE_TASK3_H
