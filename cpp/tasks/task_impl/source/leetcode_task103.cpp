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

static std::vector<std::vector<int>> zigzagLevelOrder2(TreeNode* root) {
    if (!root) return {};
    std::vector<std::vector<int>> result;
    std::vector<int> line;
    std::stack<TreeNode*> stack1, stack2;  // 此次应该使用stack 因为无论顺序还是逆序遍历 都需要将子树逆序
    stack1.push(root);
    bool flag = true;
    while (!stack1.empty()) {
        TreeNode* cur = stack1.top();
        line.push_back(cur->val);
        stack1.pop();
        if (flag) {  // 需要区别的是左右子树的顺序
            if (cur->left) stack2.push(cur->left);
            if (cur->right) stack2.push(cur->right);
        } else {
            if (cur->right) stack2.push(cur->right);
            if (cur->left) stack2.push(cur->left);
        }
        if (stack1.empty()) {
            flag = !flag;
            result.emplace_back(std::move(line));
            std::swap(stack1, stack2);
        }
    }
    return result;
}

std::vector<std::vector<int>> LeetcodeTask103::solve(TreeNode* root) const { return zigzagLevelOrder2(root); }
