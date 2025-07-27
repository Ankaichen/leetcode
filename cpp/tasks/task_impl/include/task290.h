/**
  ******************************************************************************
  * @file           : task290.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-28
  ******************************************************************************
  */

#ifndef LEETCODE_TASK290_H
#define LEETCODE_TASK290_H

#include "../../core/task.hpp"

class Task290 : public Task<290, bool(const std::string&, const std::string&)> {
public:
    Task290() ;
    ~Task290() noexcept override = default;
    std::string title() const override {
        return "单词规律";
    }
    bool solve(const std::basic_string<char> &pattern, const std::basic_string<char> &s) const override;
};

#endif //LEETCODE_TASK290_H
