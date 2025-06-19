/**
  ******************************************************************************
  * @file           : task242.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK242_H
#define LEETCODE_TASK242_H

#include "../task.hpp"

class Task242 : public Task<242, bool(const std::string &, const std::string &)> {
public:
    Task242();

    ~Task242() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "有效的字母异位词";
    }

    [[nodiscard]] bool solve(const std::string &s, const std::string &t) const override;
};

#endif //LEETCODE_TASK242_H
