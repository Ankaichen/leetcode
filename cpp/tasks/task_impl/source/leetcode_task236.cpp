/**
 ******************************************************************************
 * @file           : leetcode_task236.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-19
 ******************************************************************************
 */

#include "../include/leetcode_task236.h"

static TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 通过深搜构建节点反向关系 同时获取目标节点深度
    // 使用Leetcode 160的解法
    std::unordered_map<TreeNode*, TreeNode*> parent_map{};
    int depth_p, depth_q;
    auto dfs = [&parent_map, &depth_p, &depth_q](auto& self, TreeNode* root, TreeNode* p, TreeNode* q, int depth) -> void {
        if (root == p) {
            depth_p = depth;
        };
        if (root == q) {
            depth_q = depth;
        }
        if (!root) return;
        if (root->left) {
            parent_map.insert(std::make_pair(root->left, root));
            self(self, root->left, p, q, depth + 1);
        }
        if (root->right) {
            parent_map.insert(std::make_pair(root->right, root));
            self(self, root->right, p, q, depth + 1);
        }
        return;
    };
    dfs(dfs, root, p, q, 0);
    if (depth_p < depth_q) {
        std::swap(depth_p, depth_q);
        std::swap(p, q);
    }
    for (; depth_p > depth_q; --depth_p, p = parent_map.find(p)->second);
    while (p && q) {
        if (p == q) return p;
        auto parent_p = parent_map.find(p)->second;
        auto parent_q = parent_map.find(q)->second;
        p = parent_p;
        q = parent_q;
    }
    return root;
}

static TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 递归解法
    // 将找到的目标节点由递归树返回 找到单侧时返回单侧节点 如果双侧都找到改为返回祖先节点
    // 由于只有满足条件的祖先节点能够同时找到双侧 其它情况都只能返回单侧 所以能够保证递归树能够返回最终结果
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
    TreeNode* leftNode = lowestCommonAncestor1(root->left, p, q);  // 查找左右子树有没有
    TreeNode* rightNode = lowestCommonAncestor1(root->right, p, q);
    if (leftNode && rightNode) return root;             // 如果左右子树都能找到 自己就是最近的祖先节点
    if (root == p || root == q) return root;            // 如果自己就是目标节点 返回自己表示找到了
    return leftNode != nullptr ? leftNode : rightNode;  // 返回找到的一侧 如果没有就返回nullptr
}

static TreeNode* getTreeNodeByValue(TreeNode* root, int value) {
    if (!root) return nullptr;
    std::deque<TreeNode*> queue{root};
    while (!queue.empty()) {
        TreeNode* node = queue.front();
        if (node->val == value) return node;
        if (node->left) queue.push_back(node->left);
        if (node->right) queue.push_back(node->right);
        queue.pop_front();
    }
    return nullptr;
}

int LeetcodeTask236::solve(TreeNode* root, int p, int q) const {
    return lowestCommonAncestor2(root, getTreeNodeByValue(root, p), getTreeNodeByValue(root, q))->val;
}