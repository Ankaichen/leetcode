/**
  ******************************************************************************
  * @file           : task2.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-19
  ******************************************************************************
  */

#ifndef LEETCODE_TASK2_HPP
#define LEETCODE_TASK2_HPP

#include "../task.hpp"

class Task2 : public Task<2, ListNode *(ListNode *, ListNode *)> {
public:
    Task2();

    ~Task2() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两数相加";
    }

    [[nodiscard]] ListNode *solve(ListNode *l1, ListNode *l2) const override;
};

Task2::Task2() {
    this->addTestCase("l1 = [2,4,3]; l2 = [5,6,4]", "[7,0,8]");
    this->addTestCase("l1 = [0]; l2 = [0]", "[0]");
    this->addTestCase("l1 = [9,9,9,9,9,9,9]; l2 = [9,9,9,9]", "[8,9,9,9,0,0,0,1]");
}

ListNode *Task2::solve(ListNode *l1, ListNode *l2) const {
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
        return new ListNode(result, this->solve(l1, l2));
    } else {
        return new ListNode(result, nullptr);
    }
}

#endif //LEETCODE_TASK2_HPP
