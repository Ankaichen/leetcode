/**
  ******************************************************************************
  * @file           : leetcode_task21.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-8-9
  ******************************************************************************
  */

#include "../include/leetcode_task21.h"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode head, *p = &head;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list2) list1 = list2;
    p->next = list1;
    list1 = list2 = nullptr;
    return head.next;
}

ListNode *LeetcodeTask21::solve(ListNode *list1, ListNode *list2) const {
    return mergeTwoLists(list1, list2);
}