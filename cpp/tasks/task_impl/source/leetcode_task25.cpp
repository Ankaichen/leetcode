/**
  ******************************************************************************
  * @file           : leetcode_task25.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-8-6
  ******************************************************************************
  */

#include "../include/leetcode_task25.h"

static ListNode *reverse(ListNode *head, int k) { // head 为头节点 反转head后的k个节点
    if (!head) return nullptr;
    ListNode *p = head->next, *last = head->next;
    while (p && k) {
        ListNode *temp = p->next;
        p->next = head->next;
        head->next = p;
        p = temp;
        --k;
    }
    if (last) last->next = p;
    return last; // 返回反转后 第k个节点 即这一组的最后一个节点
}

static ListNode *seek(ListNode *head, int k) { // 从head开始 找后面第k个节点 没有就返回nullptr
    for (int i = 0; i < k && head; ++i) {
        head = head->next;
    }
    return head;
}

static ListNode *reverseKGroup1(ListNode *head, int k) {
    ListNode tempHead(0, head);
    head = &tempHead;
    while (seek(head, k)) { // 判断节点数量
        head = reverse(head, k); // 反转链表 或许下一组的头节点
    }
    return tempHead.next;
}

ListNode *LeetcodeTask25::solve(ListNode *head, int k) const {
    return reverseKGroup1(head, k);
}
