/**
 ******************************************************************************
 * @file           : leetcode_task141.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-9-22
 ******************************************************************************
 */

#include "../include/leetcode_task141.h"

static bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *p1 = head, *p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return true;
    }
    return false;
}

bool LeetcodeTask141::solve(ListNode *head, int pos) const {
    if (head && pos != -1) {
        ListNode *tail = head, *p = head;
        for (; tail->next; tail = tail->next);
        for (int i = 0; i < pos; ++i, p = p->next);
        tail->next = p;
    }
    return hasCycle(head);
}