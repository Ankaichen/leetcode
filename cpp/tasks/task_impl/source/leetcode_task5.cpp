/**
 ******************************************************************************
 * @file           : task5.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-9
 ******************************************************************************
 */

#include "../include/leetcode_task5.h"

std::string longestPalindrome4(const std::string &s) {  // 中心扩展算法
    auto expandAroundCenter = [&s](int left, int right) -> std::pair<int, int> {
        int target_left, target_right;
        for (int i = 0; (target_left = left - i) >= 0 & (target_right = right + i) < s.size() && s[target_left] == s[target_right]; ++i);
        return std::make_pair(target_left + 1, target_right - 1);
    };
    int max_size = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto [left1, right1] = expandAroundCenter(i, i);
        auto [left2, right2] = expandAroundCenter(i, i + 1);
        int size1, size2;
        if ((size1 = right1 - left1 + 1) < (size2 = right2 - left2 + 1)) {
            size1 = size2;
            left1 = left2;
        }
        if (size1 > max_size) {
            max_size = size1;
            left = left1;
        }
    }
    return s.substr(left, max_size);
}

std::string longestPalindrome3(const std::string &s) {  // 动态规划 一维dp数组
    // 可将二维dp数组的动态规划 简化为一维dp数组
    // 由于dp[i][j]是由dp[i+1][j-1]计算得到的 因此可以不断覆盖dp数组
    // 此时需要j也是反序遍历 这样在计算dp[j]时 dp[j-1]还是上一次得到的值 没有被覆盖
    std::vector<bool> dp(s.size(), false);
    auto isPalindrome = [&s, &dp](int left, int right) -> bool {
        if (left == right) return dp[right] = true;
        if (left + 1 == right && s[left] == s[right]) return dp[right] = true;
        if (dp[right - 1] && s[left] == s[right]) return dp[right] = true;
        return dp[right] = false;
    };
    int max_size = 0, left = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = s.size() - 1; j >= i; --j) {
            int temp_size;
            if (isPalindrome(i, j) && max_size < (temp_size = j - i + 1)) {
                max_size = temp_size;
                left = i;
            }
        }
    }
    return s.substr(left, max_size);
}

std::string longestPalindrome2(const std::string &s) {  // 动态规划 二维dp数组
    // 子问题定义为 dp[i][j]表示子串s[i...j]是否为回文串
    // 当i==j时 长度为1是回文串 当j-i=1时 字符相同为回文串 else s[i+1...j-1]是回文串且s[i]==s[j] 是回文串
    // 因此使用动态规划 只能够替换暴力搜索时判断是否为回文串的部分 能够减少一层循环
    // 由于需要根据dp[i+1][...]计算dp[i][...] 因此i的循环是反序的
    std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
    auto isPalindrome = [&s, &dp](int left, int right) -> bool {
        if (left == right) return dp[left][right] = true;
        if (left + 1 == right && s[left] == s[right]) return dp[left][right] = true;
        if (dp[left + 1][right - 1] && s[left] == s[right]) return dp[left][right] = true;
        return dp[left][right];
    };
    int max_size = 0, left = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = i; j < s.size(); ++j) {
            int temp_size;
            if (isPalindrome(i, j) && max_size < (temp_size = j - i + 1)) {
                max_size = temp_size;
                left = i;
            }
        }
    }
    return s.substr(left, max_size);
}

std::string longestPalindrome1(const std::string &s) {  // 暴力搜索
    auto isPalindrome = [&s](int left, int right) -> bool {
        int size = right - left + 1;
        for (int i = 0; i < size / 2; ++i) {
            if (s[left + i] != s[right - i]) return false;
        }
        return true;
    };
    int max_size = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + max_size; j < s.size(); ++j) {
            if (isPalindrome(i, j)) {
                max_size = j - i + 1;
                left = i;
            }
        }
    }
    return s.substr(left, max_size);
}

std::string LeetcodeTask5::solve(const std::string &s) const { return longestPalindrome4(s); }