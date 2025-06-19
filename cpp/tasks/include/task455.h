/**
  ******************************************************************************
  * @file           : task455.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK455_H
#define LEETCODE_TASK455_H

#include "../task.hpp"

class Task455 : public Task<455, int(const std::vector<int>&, const std::vector<int>&)> {
public:
    Task455();
    ~Task455() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "分发饼干";
    }
    [[nodiscard]] int solve(const std::vector<int> &g, const std::vector<int> &s) const override;
};

#endif //LEETCODE_TASK455_H
