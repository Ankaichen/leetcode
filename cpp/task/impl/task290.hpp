/**
  ******************************************************************************
  * @file           : task290.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-28
  ******************************************************************************
  */

#ifndef LEETCODE_TASK290_HPP
#define LEETCODE_TASK290_HPP

#include "../task.hpp"

class Task290 : public Task<290, bool(const std::string&, const std::string&)> {
public:
    Task290() ;
    ~Task290() noexcept override = default;
    std::string title() const override {
        return "单词规律";
    }
    bool solve(const std::basic_string<char> &pattern, const std::basic_string<char> &s) const override;
};

Task290::Task290() {
    this->addTestCase(R"(pattern = "abba"; s = "dog cat cat dog")", "true");
    this->addTestCase(R"(pattern = "abba"; s = "dog cat cat fish")", "false");
    this->addTestCase(R"(pattern = "aaaa"; s = "dog cat cat dog")", "false");
}

bool wordPattern1(const std::string &pattern, const std::string &s) {
    std::unordered_map<char, std::string> map;
    std::stringstream ss;
    int index = 0;
    for (auto i = s.cbegin(); ; ++i) {
        if (index >= pattern.size()) return false;
        if (*i == ' ' || i == s.cend()) {
            const std::string tempStr = ss.str();
            const char &pc = pattern[index++];
            auto iter = map.find(pc);
            if (iter == map.end()) {
                map.insert(std::make_pair(pc, tempStr));
            } else if (iter->second != tempStr) {
                return false;
            }
            { decltype(ss) temp = std::move(ss); }
            if (i == s.cend()) break;
        } else {
            ss << *i;
        }
    }
    if (index < pattern.size()) return false;
    std::unordered_set<std::string> set;
    for (const auto &k : map) {
        auto iter = set.find(k.second);
        if (iter != set.end()) {
            return false;
        } else {
            set.insert(k.second);
        }
    }
    return true;
}

bool wordPattern2(const std::string &pattern, const std::string &s) {
    std::unordered_map<char, std::string> mapPatS;
    std::unordered_map<std::string, char> mapSPat;
    std::stringstream ss(s);
    std::vector<std::string> strVec;
    std::string word;
    while (ss >> word) strVec.emplace_back(std::move(word));
    if (pattern.size() != strVec.size()) return false;
    for (int i = 0; i < pattern.size(); ++i) {
        char c = pattern[i];
        const std::string &str = strVec[i];
        auto iterPatS = mapPatS.find(c);
        auto iterSPat = mapSPat.find(str);
        if (iterPatS == mapPatS.end() && iterSPat == mapSPat.end()) {
            mapPatS.insert(std::make_pair(c, str));
            mapSPat.insert(std::make_pair(str, c));
        } else if (iterPatS == mapPatS.end() || iterSPat == mapSPat.end()) {
            return false;
        } else if (iterPatS->second != str || iterSPat->second != c) {
            return false;
        }
    }
    return true;
}

bool Task290::solve(const std::basic_string<char> &pattern, const std::basic_string<char> &s) const {
    return wordPattern2(pattern, s);
}

#endif //LEETCODE_TASK290_HPP
