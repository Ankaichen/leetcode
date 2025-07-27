/**
  ******************************************************************************
  * @file           : task19.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-20
  ******************************************************************************
  */

#ifndef LEETCODE_TASK19_H
#define LEETCODE_TASK19_H

#include "../../core/task.hpp"

class Task19 : public Task<19, ListNode*(ListNode*, int)> {
public:
    Task19();

    ~Task19() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "删除链表的倒数第 N 个结点";
    }

    [[nodiscard]] ListNode * solve(ListNode *head, int n) const override;
};

#endif //LEETCODE_TASK19_H
