/**
  ******************************************************************************
  * @file           : task2.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-19
  ******************************************************************************
  */

#ifndef LEETCODE_TASK2_H
#define LEETCODE_TASK2_H

#include "../task.hpp"

class Task2 : public Task<2, ListNode *(ListNode *, ListNode *)> {
public:
    Task2();

    ~Task2() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两数相加";
    }

    [[nodiscard]] ListNode *solve(ListNode *l1, ListNode *l2) const override;
};

#endif //LEETCODE_TASK2_H
