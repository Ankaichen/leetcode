/**
  ******************************************************************************
  * @file           : task383.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task383.h"

Task383::Task383() {
    this->addTestCase(R"(ransomNote = "a"; magazine = "b")", "false");
    this->addTestCase(R"(ransomNote = "aa"; magazine = "ab")", "false");
    this->addTestCase(R"(ransomNote = "aa"; magazine = "aab")", "true");
//    this->addTestCase(R"(ransomNote = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; magazine = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")", "true");
}

static bool canConstruct1(const std::string& ransomNote, const std::string& magazine) {
    std::unordered_map<char, int> map;
    for (const auto &c: magazine) {
        auto iter = map.find(c);
        if (iter != map.end()) {
            ++iter->second;
        } else {
            map.insert(std::make_pair(c, 1));
        }
    }
    for (const auto &c : ransomNote) {
        auto iter = map.find(c);
        if (iter != map.end() && iter->second > 0) {
            --iter->second;
        } else {
            return false;
        }
    }
    return true;
}

static bool canConstruct2(const std::string& ransomNote, const std::string& magazine) {
    int arr[26] = { 0 };
    for (const auto &c: magazine) {
        ++arr[c - 'a'];
    }
    for (const auto &c : ransomNote) {
        if (arr[c - 'a'] <= 0) {
            return false;
        }
        --arr[c - 'a'];
    }
    return true;
}

bool Task383::solve(const std::string &ransomNote, const std::string &magazine) const {
    return canConstruct2(ransomNote, magazine);
}