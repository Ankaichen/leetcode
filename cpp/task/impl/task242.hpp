/**
  ******************************************************************************
  * @file           : task242.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK242_HPP
#define LEETCODE_TASK242_HPP

#include "../task.hpp"

class Task242 : public Task<242, bool(const std::string &, const std::string &)> {
public:
    Task242();

    ~Task242() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "有效的字母异位词";
    }

    [[nodiscard]] bool solve(const std::string &s, const std::string &t) const override;
};

Task242::Task242() {
    this->addTestCase(R"(s = "anagram"; t = "nagaram")", "true");
    this->addTestCase(R"(s = "rat"; t = "car")", "false");
}

#include <unordered_map>

bool isAnagram(const std::string &s, const std::string &t) {
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

bool Task242::solve(const std::string &s, const std::string &t) const {
    return isAnagram(s, t);
}

#endif //LEETCODE_TASK242_HPP
