/**
  ******************************************************************************
  * @file           : leetcode_task203.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task203.h"

static ListNode *removeElements1(ListNode *head, int val) {
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

static ListNode *removeElements2(ListNode *head, int val) {
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

ListNode *LeetcodeTask203::solve(ListNode *head, int val) const {
    return removeElements2(head, val);
}