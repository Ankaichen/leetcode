/**
  ******************************************************************************
  * @file           : leetcode_task2.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task2.h"

static ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    int one_num = 0, up_num = 0;
    ListNode l_sum, *cur = &l_sum;
    while(l1 != nullptr && l2 != nullptr) {
        one_num = l1->val + l2->val + up_num;
        up_num = one_num / 10;
        one_num %= 10;
        cur->next = new ListNode(one_num);
        cur = cur->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != nullptr) {
        one_num = l1->val + up_num;
        up_num = one_num / 10;
        one_num %= 10;
        cur->next = new ListNode(one_num);
        cur = cur->next;
        l1 = l1->next;
    }
    while(l2 != nullptr) {
        one_num = l2->val + up_num;
        up_num = one_num / 10;
        one_num %= 10;
        cur->next = new ListNode(one_num);
        cur = cur->next;
        l2 = l2->next;
    }
    if(up_num != 0)
        cur->next = new ListNode(up_num);
    return l_sum.next;
}

static ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    int up_num = 0;
    ListNode* l_sum = l1;
    while(l1 != nullptr && l2 != nullptr) {
        l1->val = l1->val + l2->val + up_num;
        up_num = l1->val / 10;
        if(l1->next == nullptr && (up_num != 0 || l2->next != nullptr)) {
            l1->next = new ListNode(0);
        }
        l1->val %= 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != nullptr) {
        l1->val = l1->val + up_num;
        up_num = l1->val / 10;
        if(l1->next == nullptr && up_num != 0) {
            l1->next = new ListNode(0);
        }
        l1->val %= 10;
        l1 = l1->next;
    }
    return l_sum;
}

static ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
    int result = l1->val + l2->val, up_num = result / 10;
    result %= 10;
    if (l1->next != nullptr || l2->next != nullptr || up_num != 0) {
        ListNode temp_node_l1(0), temp_node_l2(0);
        if (l1->next == nullptr) {
            l1 = &temp_node_l1;
        } else {
            l1 = l1->next;
        }
        if (l2->next == nullptr) {
            l2 = &temp_node_l2;
        } else {
            l2 = l2->next;
        }
        l1->val += up_num;
        return new ListNode(result, addTwoNumbers3(l1, l2));
    } else {
        return new ListNode(result, nullptr);
    }
}

ListNode *LeetcodeTask2::solve(ListNode *l1, ListNode *l2) const {
    return addTwoNumbers2(l1, l2);
}
