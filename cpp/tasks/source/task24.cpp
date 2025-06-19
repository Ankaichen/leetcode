/**
  ******************************************************************************
  * @file           : task24.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */
#include "../include/task24.h"

Task24::Task24() {
    this->addTestCase("head = [1,2,3,4,5,6,7]", "[2,1,4,3,6,5,7]");
    this->addTestCase("head = [1,2,3,4]", "[2,1,4,3]");
    this->addTestCase("head = []", "[]");
    this->addTestCase("head = [1]", "[1]");
}

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

ListNode *Task24::solve(ListNode *head) const {
    return swapPairs1(head);
}