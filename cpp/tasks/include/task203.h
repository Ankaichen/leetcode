/**
  ******************************************************************************
  * @file           : task203.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK203_H
#define LEETCODE_TASK203_H

#include "../task.hpp"

class Task203 : public Task<203, ListNode *(ListNode *, int)> {
public:
    Task203();

    ~Task203() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "移除链表元素";
    }

    [[nodiscard]] ListNode *solve(ListNode *head, int val) const override;
};

#endif //LEETCODE_TASK203_H
