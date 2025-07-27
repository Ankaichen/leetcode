/**
  ******************************************************************************
  * @file           : task383.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-25
  ******************************************************************************
  */

#ifndef LEETCODE_TASK383_H
#define LEETCODE_TASK383_H

#include "../../core/task.hpp"

class Task383 : public Task<383, bool(const std::string &, const std::string &)> {
public:
    Task383();

    ~Task383() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "赎金信";
    }

    [[nodiscard]] bool solve(const std::string &ransomNote, const std::string &magazine) const override;
};

#endif //LEETCODE_TASK383_H
