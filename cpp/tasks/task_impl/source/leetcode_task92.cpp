/**
 ******************************************************************************
 * @file           : leetcode_task92.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-19
 ******************************************************************************
 */

#include "../include/leetcode_task92.h"

static ListNode* reverseBetween1(ListNode* head, int left, int right) {
    auto seek = [](ListNode* head, int k) -> ListNode* {
        for (int i = 0; i < k && head; ++i, head = head->next);
        return head;
    };
    auto reversek = [](ListNode* head, int k) -> ListNode* {
        ListNode *p = head->next, *q = p;
        head->next = nullptr;
        for (int i = 0; i < k && p; ++i) {
            ListNode* temp = p->next;
            p->next = head->next;
            head->next = p;
            p = temp;
        }
        return q;
    };
    ListNode temp_head(0, head);
    ListNode *reverse_head = seek(&temp_head, left - 1), *reverse_tail = seek(reverse_head, right - left + 2);
    reversek(reverse_head, right - left + 1)->next = reverse_tail;
    return temp_head.next;
}

ListNode* LeetcodeTask92::solve(ListNode* head, int left, int right) const { return reverseBetween1(head, left, right); }