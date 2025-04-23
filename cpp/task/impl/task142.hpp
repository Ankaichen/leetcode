/**
  ******************************************************************************
  * @file           : task142.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-23
  ******************************************************************************
  */

#ifndef LEETCODE_TASK142_HPP
#define LEETCODE_TASK142_HPP

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

Task142::Task142() {
    this->addTestCase("head = [3,2,0,-4]; pos = 1", "1");
    this->addTestCase("head = [1,2]; pos = 0", "0");
    this->addTestCase("head = [1]; pos = -1", "-1");
}

#include <unordered_set>

ListNode *detectCycle1(ListNode *head) {
    std::unordered_set<ListNode*> node_set;
    while(head && !node_set.count(head)) {
        node_set.insert(head);
        head = head->next;
    }
    return head;
}

ListNode *detectCycle2(ListNode *head) {
    if (head == nullptr) return nullptr;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (slow != fast || !(fast && fast->next)) return nullptr;
    ListNode *p = head;
    for (; p != slow; p = p->next, slow = slow->next);
    return p;
}

int Task142::solve(ListNode *head, int pos) const {
    if (head && pos != -1) {
        ListNode *tail = head, *p = head;
        for (; tail->next; tail = tail->next);
        for (int i = 0; i < pos; ++i, p = p->next);
        tail->next = p;
    }
    ListNode *resP = detectCycle2(head);
    if (head && pos != -1) {
        ListNode *p = head;
        for (int i = 0; i <= pos; ++i, p = p->next) {
            if (resP == p) return i;
        }
        return -2;
    } else {
        return (resP == nullptr) ? -1 : -2;
    }
}

#endif //LEETCODE_TASK142_HPP
