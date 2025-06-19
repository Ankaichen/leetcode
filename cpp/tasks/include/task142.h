/**
  ******************************************************************************
  * @file           : task142.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK142_H
#define LEETCODE_TASK142_H

#include "../task.hpp"

class Task142 : public Task<142, int(ListNode *, int)> {
public:
    Task142();

    ~Task142() noexcept override = default;

    std::string title() const override {
        return "环形链表 II";
    }

    int solve(ListNode *head, int pos) const override;
};

#endif //LEETCODE_TASK142_H
