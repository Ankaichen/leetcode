/**
  ******************************************************************************
  * @file           : leetcode_task206.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task206.h"

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

ListNode *LeetcodeTask206::solve(ListNode *head) const {
    return reverseList2(head);
}