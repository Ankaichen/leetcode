/**
 ******************************************************************************
 * @file           : leetcode_task20.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-13
 ******************************************************************************
 */

#include "../include/leetcode_task20.h"

bool isValid1(std::string &s) {
    std::stack<char> stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.empty() || stack.top() != '(') return false;
            stack.pop();
        } else if (c == ']') {
            if (stack.empty() || stack.top() != '[') return false;
            stack.pop();
        } else if (c == '}') {
            if (stack.empty() || stack.top() != '{') return false;
            stack.pop();
        } else
            return false;
    }
    return stack.empty();
}

bool LeetcodeTask20::solve(const std::string &s) const { return isValid1(const_cast<std::string &>(s)); }