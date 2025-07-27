/**
  ******************************************************************************
  * @file           : task142.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task142.h"

Task142::Task142() {
    this->addTestCase("head = [3,2,0,-4]; pos = 1", "1");
    this->addTestCase("head = [1,2]; pos = 0", "0");
    this->addTestCase("head = [1]; pos = -1", "-1");
}

static ListNode *detectCycle1(ListNode *head) {
    std::unordered_set<ListNode*> node_set;
    while(head && !node_set.count(head)) {
        node_set.insert(head);
        head = head->next;
    }
    return head;
}

static ListNode *detectCycle2(ListNode *head) {
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