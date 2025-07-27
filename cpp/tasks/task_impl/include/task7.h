/**
  ******************************************************************************
  * @file           : task7.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-29
  ******************************************************************************
  */

#ifndef LEETCODE_TASK7_H
#define LEETCODE_TASK7_H

#include "../../core/task.hpp"

class Task7 : public Task<7, int(int)> {
public:
    Task7();
    ~Task7() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "整数反转";
    }
    [[nodiscard]] int solve(int x) const override;
};

#endif //LEETCODE_TASK7_H
