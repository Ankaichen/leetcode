/**
  ******************************************************************************
  * @file           : task349.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK349_H
#define LEETCODE_TASK349_H

#include "../task.hpp"

#include <set>

class Task349 : public Task<349, std::set<int>(const std::vector<int> &, const std::vector<int> &)> {
public:
    Task349();

    ~Task349() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两个数组的交集";
    }

    [[nodiscard]] std::set<int> solve(const std::vector<int> &num1, const std::vector<int> &num2) const override;
};

#endif //LEETCODE_TASK349_H
