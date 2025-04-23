/**
  ******************************************************************************
  * @file           : task206.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK206_HPP
#define LEETCODE_TASK206_HPP

#include "../task.hpp"

class Task206 : public Task<206, ListNode *(ListNode *)> {
public:
    Task206();

    ~Task206() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "反转链表";
    }

    [[nodiscard]] ListNode *solve(ListNode *head) const override;
};

Task206::Task206() {
    this->addTestCase("head = [1,2,3,4,5]", "[5,4,3,2,1]");
    this->addTestCase("head = [1,2]", "[2,1]");
    this->addTestCase("head = [1]", "[1]");
    this->addTestCase("head = []", "[]");
}

ListNode *reverseList1(ListNode *head) {
    ListNode temp_head, *temp;
    while (head) {
        temp = temp_head.next;
        temp_head.next = head;
        head = head->next;
        temp_head.next->next = temp;
    }
    return temp_head.next;
}

ListNode *reverseList2(ListNode *head) {
    ListNode *p = head, *temp;
    head = nullptr;
    while (p != nullptr) {
        temp = p;
        p = p->next;
        temp->next = head;
        head = temp;
    }
    return head;
}

ListNode *Task206::solve(ListNode *head) const {
    return reverseList2(head);
}

#endif //LEETCODE_TASK206_HPP
