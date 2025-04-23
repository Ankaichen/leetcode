/**
  ******************************************************************************
  * @file           : task203.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK203_HPP
#define LEETCODE_TASK203_HPP

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

Task203::Task203() {
    this->addTestCase("head = [1,2,6,3,4,5,6]; val = 6", "[1,2,3,4,5]");
    this->addTestCase("head = []; val = 1", "[]");
    this->addTestCase("head = [7,7,7,7]; val = 7", "[]");
}

ListNode *removeElements1(ListNode *head, int val) {
    ListNode temp_head(0, head), *cur = &temp_head, *temp;
    while(cur->next) {
        if(cur->next->val == val) {
            temp = cur->next->next;
            delete cur->next;
            cur->next = temp;
        } else {
            cur = cur->next;
        }
    }
    return temp_head.next;
}

ListNode *removeElements2(ListNode *head, int val) {
    ListNode tempHead(-val, head), *p = &tempHead;
    while (p != nullptr && p->next != nullptr) {
        if (p->next->val == val) {
            head = p->next;
            p->next = head->next;
            delete head;
        } else {
            p = p->next;
        }
    }
    return tempHead.next;
}

ListNode *Task203::solve(ListNode *head, int val) const {
    return removeElements2(head, val);
}

#endif //LEETCODE_TASK203_HPP
