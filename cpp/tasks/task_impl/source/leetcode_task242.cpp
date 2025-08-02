/**
  ******************************************************************************
  * @file           : leetcode_task242.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task242.h"

static bool isAnagram(const std::string &s, const std::string &t) {
    std::unordered_map<char, int> hash_map;
    for (char c : s) {
        auto iter = hash_map.find(c);
        if (iter == hash_map.end()) {
            hash_map.insert(std::make_pair(c, 1));
        } else {
            ++iter->second;
        }
    }
    for (char c : t) {
        auto iter = hash_map.find(c);
        if (iter == hash_map.end()) {
            return false;
        } else {
            --iter->second;
        }
    }
    return std::ranges::all_of(hash_map, [] (auto &i) -> bool {
        return i.second == 0;
    });
}

bool LeetcodeTask242::solve(const std::string &s, const std::string &t) const {
    return isAnagram(s, t);
}