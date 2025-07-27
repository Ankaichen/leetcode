/**
  ******************************************************************************
  * @file           : task541.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-26
  ******************************************************************************
  */

#ifndef LEETCODE_TASK541_H
#define LEETCODE_TASK541_H

#include "../../core/task.hpp"

class Task541 : public Task<541, std::string(const std::string &, int)> {
public:
    Task541();

    ~Task541() noexcept override = default;

    std::string title() const override {
        return "反转字符串 II";
    }

    std::string solve(const std::string &s, int k) const override;
};

#endif //LEETCODE_TASK541_H
