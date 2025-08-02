/**
  ******************************************************************************
  * @file           : leetcode_task2416.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task2416.h"

static bool isPrefix(const std::string &str, const std::string &prefix) {
    if (str.size() < prefix.size())
        return false;
    for (int i = 0; i < prefix.size(); ++i) {
        if (str[i] != prefix[i])
            return false;
    }
    return true;
}

static std::vector<int> sumPrefixScores1(std::vector<std::string> &words) {
    std::vector<int> result(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
        for (int j = 1; j <= words[i].size(); ++j) {
            for (int k = 0; k < words.size(); ++k) {
                result[i] += isPrefix(words[k], words[i].substr(0, j));
            }
        }
    }
    return result;
}

struct TNode {
    TNode *childrens[26] = {nullptr};
    int score = 0;

    ~TNode() noexcept {
        for (auto &children: this->childrens) {
            delete children;
        }
    }
};

static std::vector<int> sumPrefixScores2(std::vector<std::string> &words) {
    auto *root = new TNode();
    for (const auto &word: words) {
        TNode *cur = root;
        for (const char c: word) {
            int index = c - 'a';
            if (cur->childrens[index] == nullptr) {
                cur->childrens[index] = new TNode();
            }
            cur = cur->childrens[index];
            ++cur->score;
        }
    }
    std::vector<int> result(words.size(), 0);
    int wi = 0;
    for (const auto &word: words) {
        TNode *cur = root;
        for (const char c: word) {
            cur = cur->childrens[c - 'a'];
            result[wi] += cur->score;
        }
        ++wi;
    }
    delete root;
    return result;
}

std::vector<int> LeetcodeTask2416::solve(const std::vector<std::string> &words) const {
    return sumPrefixScores2(const_cast<std::vector<std::string> &>(words));
}