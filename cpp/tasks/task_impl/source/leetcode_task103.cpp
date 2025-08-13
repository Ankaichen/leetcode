/**
 ******************************************************************************
 * @file           : leetcode_task103.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-13
 ******************************************************************************
 */

#include "../include/leetcode_task103.h"

static std::vector<std::vector<int>> zigzagLevelOrder1(TreeNode* root) {
    if (root == nullptr) return {};
    std::vector<std::vector<int>> result{};
    std::vector<int> tempRes{};
    std::deque<TreeNode*> queue1{root}, queue2;
    bool flag = true;
    while (!queue1.empty()) {
        TreeNode* temp;
        temp = queue1.back();
        queue1.pop_back();
        tempRes.push_back(temp->val);
        if (flag) {
            if (temp->left) queue2.push_back(temp->left);
            if (temp->right) queue2.push_back(temp->right);
        } else {
            if (temp->right) queue2.push_back(temp->right);
            if (temp->left) queue2.push_back(temp->left);
        }
        if (queue1.empty()) {
            result.emplace_back(std::move(tempRes));
            std::swap(queue1, queue2);
            flag = !flag;
        }
    }
    return result;
}

std::vector<std::vector<int>> LeetcodeTask103::solve(TreeNode* root) const { return zigzagLevelOrder1(root); }
