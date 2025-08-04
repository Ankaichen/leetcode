/**
  ******************************************************************************
  * @file           : task3.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task3.h"

static int lengthOfLongestSubstring1(const std::string &s) {
    if (s.empty()) return 0;
    std::unordered_set<char> set; // 字符集合
    int left = 0, right = 1; // 双指针
    int length = 1;
    set.insert(s[0]);
    for (;right < s.size();) { // 查找是否有重复
        auto iter = set.find(s[right]);
        if (iter == set.end()) { // 没有重复加入 右指针移动
            length = std::max(length, right - left + 1);
            set.insert(s[right++]);
        } else { // 有重复删除 双指针同时移动
            for (;s[left] != s[right]; ++left) { // 删除左指针字符 直到和右指针字符相同
                set.erase(s[left]);           // 由于右指针字符判断存在后 并没有再次插入 因此左指针找到右指针相同字符后 不需要删除此字符
            } // 双指针同时右移 即使用右指针字符替换左指针相同字符
            ++left;
            ++right;
        }
    }
    return length;
}

int LeetcodeTask3::solve(const std::string &s) const {
    return lengthOfLongestSubstring1(s);
}