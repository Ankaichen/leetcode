/**
  ******************************************************************************
  * @file           : task206.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task206.h"

Task206::Task206() {
    this->addTestCase("head = [1,2,3,4,5]", "[5,4,3,2,1]");
    this->addTestCase("head = [1,2]", "[2,1]");
    this->addTestCase("head = [1]", "[1]");
    this->addTestCase("head = []", "[]");
}

static ListNode *reverseList1(ListNode *head) {
    ListNode temp_head, *temp;
    while (head) {
        temp = temp_head.next;
        temp_head.next = head;
        head = head->next;
        temp_head.next->next = temp;
    }
    return temp_head.next;
}

static ListNode *reverseList2(ListNode *head) {
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