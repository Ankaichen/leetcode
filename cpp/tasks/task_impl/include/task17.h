/**
  ******************************************************************************
  * @file           : task17.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK17_H
#define LEETCODE_TASK17_H

#include "../../core/task.hpp"

class Task17 : public Task<17, std::set<std::string>(const std::string&)> {
public:
    Task17();
    ~Task17() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "电话号码的字母组合";
    }
    [[nodiscard]] std::set<std::string> solve(const std::string& digits) const override;
};

#endif //LEETCODE_TASK17_H
