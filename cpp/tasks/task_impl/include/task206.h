/**
  ******************************************************************************
  * @file           : task206.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK206_H
#define LEETCODE_TASK206_H

#include "../../core/task.hpp"

class Task206 : public Task<206, ListNode *(ListNode *)> {
public:
    Task206();

    ~Task206() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "反转链表";
    }

    [[nodiscard]] ListNode *solve(ListNode *head) const override;
};

#endif //LEETCODE_TASK206_H
