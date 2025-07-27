/**
  ******************************************************************************
  * @file           : task19.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task19.h"

Task19::Task19() {
    this->addTestCase("head = [1,2,3,4,5]; n = 2", "[1,2,3,5]");
    this->addTestCase("head = [1]; n = 1", "[]");
    this->addTestCase("head = [1,2]; n = 1", "[1]");
}

static ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode* front = head, *after = head;
    int count = 0;
    while(after != nullptr) {
        after = after->next;
        if(count < n + 1) {
            count++;
        } else {
            front = front->next;
        }
    }
    ListNode* temp = nullptr;
    if(count == n) { // 代表要删除头节点
        temp = front;
        head = front->next;
    } else {
        temp = front->next;
        front->next = temp->next;
    }
    delete temp;
    return head;
}

static ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode temp_head(0, head), *fast = &temp_head, *slow = &temp_head;
    for(int i = 0; i < n; i++, fast = fast->next);
    while(fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }
    fast = slow->next;
    slow->next = fast->next;
    delete fast;
    return temp_head.next;
}

static ListNode* removeNthFromEnd3(ListNode* head, int n) {
    ListNode tempHead(0, head);
    ListNode *left = &tempHead, *right = &tempHead;
    for (int i = 0; i < n; ++i, right = right->next);
    for (; right->next != nullptr; right = right->next, left = left->next);
    right = left->next;
    left->next = right->next;
    delete right;
    return tempHead.next;
}

ListNode *Task19::solve(ListNode *head, int n) const {
    return removeNthFromEnd3(head, n);
}