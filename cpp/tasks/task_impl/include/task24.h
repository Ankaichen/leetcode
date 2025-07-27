/**
  ******************************************************************************
  * @file           : task24.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK24_H
#define LEETCODE_TASK24_H

#include "../../core/task.hpp"

class Task24 : public Task<24, ListNode *(ListNode *)> {
public:
    Task24();

    ~Task24() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两两交换链表中的节点";
    }

    [[nodiscard]] ListNode *solve(ListNode *head) const override;
};

#endif //LEETCODE_TASK24_H
