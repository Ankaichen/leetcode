/**
  ******************************************************************************
  * @file           : task1049.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-10
  ******************************************************************************
  */

#ifndef LEETCODE_TASK1049_H
#define LEETCODE_TASK1049_H

#include "../task.hpp"

class Task1049 : public Task<1049, int(const std::vector<int> &)> {
public:
    Task1049();

    ~Task1049() noexcept override = default;

    std::string title() const override {
        return "最后一块石头的重量 II";
    }

    int solve(const std::vector<int> &stones) const override;
};

#endif //LEETCODE_TASK1049_H
