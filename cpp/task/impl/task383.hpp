/**
  ******************************************************************************
  * @file           : task383.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-25
  ******************************************************************************
  */

#ifndef LEETCODE_TASK383_HPP
#define LEETCODE_TASK383_HPP

#include "../task.hpp"

class Task383 : public Task<383, bool(const std::string &, const std::string &)> {
public:
    Task383();

    ~Task383() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "赎金信";
    }

    [[nodiscard]] bool solve(const std::string &ransomNote, const std::string &magazine) const override;
};

Task383::Task383() {
    this->addTestCase(R"(ransomNote = "a"; magazine = "b")", "false");
    this->addTestCase(R"(ransomNote = "aa"; magazine = "ab")", "false");
    this->addTestCase(R"(ransomNote = "aa"; magazine = "aab")", "true");
//    this->addTestCase(R"(ransomNote = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; magazine = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")", "true");
}

bool canConstruct1(const std::string& ransomNote, const std::string& magazine) {
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

bool canConstruct2(const std::string& ransomNote, const std::string& magazine) {
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

#endif //LEETCODE_TASK383_HPP
