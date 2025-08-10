/**
  ******************************************************************************
  * @file           : leetcode_task102.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-8-10
  ******************************************************************************
  */

#include "../include/leetcode_task102.h"

std::vector<std::vector<int>> levelOrder1(TreeNode* root) {
    if (!root) return {};
    std::vector<std::vector<int>> result;
    std::vector<int> level;
    std::deque<TreeNode *> queue1{root}, queue2;
    while (!queue1.empty()) {
        level.push_back(queue1.front()->val);
        if (queue1.front()->left) queue2.push_back(queue1.front()->left);
        if (queue1.front()->right) queue2.push_back(queue1.front()->right);
        queue1.pop_front();
        if (queue1.empty()) {
            result.emplace_back(std::move(level));
            std::swap(queue1, queue2);
        }
    }
    return result;
}

std::vector<std::vector<int>> LeetcodeTask102::solve(TreeNode* root) const {
    return levelOrder1(root);
}
