/**
  ******************************************************************************
  * @file           : leetcode_task24.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */
#include "../include/leetcode_task24.h"

static ListNode *swapPairs1(ListNode *head) {
    ListNode temp_head(0, head), *cur = &temp_head;
    while (cur->next && cur->next->next) {
        ListNode *temp_node = cur->next->next;
        cur->next->next = temp_node->next;
        temp_node->next = cur->next;
        cur->next = temp_node;
        cur = cur->next->next;
    }
    return temp_head.next;
}

static ListNode *swapPairs2(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *after_list = swapPairs2(head->next->next), *temp_node = head->next;
    head->next = after_list;
    temp_node->next = head;
    return temp_node;
}

ListNode *LeetcodeTask24::solve(ListNode *head) const {
    return swapPairs1(head);
}