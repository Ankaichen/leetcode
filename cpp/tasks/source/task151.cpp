/**
  ******************************************************************************
  * @file           : task151.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task151.h"

Task151::Task151() {
    this->addTestCase(R"(s = "the sky is blue")", R"("blue is sky the")");
    this->addTestCase(R"(s = "  hello world  ")", R"("world hello")");
    this->addTestCase(R"(s = "a good   example")", R"("example good a")");
}

static std::string reverseWords1(std::string s) {
    std::stringstream ss{s};
    std::stack<std::string> stk;
    while (ss >> s) {
        stk.push(s);
    }
    { decltype(ss) temp; std::swap(ss, temp); }
    while (!stk.empty()) {
        ss << stk.top();
        stk.pop();
        if (!stk.empty()) ss << " ";
    }
    return ss.str();
}

static std::string reverseWords2(std::string s) {
    int slow = 0, fast = 0, reduceCount = 0;
    while (fast < s.size()) {
        for (; (fast == 0 && s[fast] == ' ') ||
               (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ');
               ++fast, ++reduceCount)
            ;
        s[slow++] = s[fast++];
    }
    if (s[s.size() - reduceCount - 1] == ' ')
        ++reduceCount;
    s.resize(s.size() - reduceCount);
    std::reverse(s.begin(), s.end());
    auto i1 = s.begin(), i2 = s.begin();
    while (i2 != s.end()) {
        if (*i2 == ' ') {
            std::reverse(i1, i2);
            i1 = i2 + 1;
        }
        ++i2;
    }
    std::reverse(i1, i2);
    return s;
}

std::string Task151::solve(const std::string &s) const {
    return reverseWords2(s);
}