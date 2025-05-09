/**
  ******************************************************************************
  * @file           : task455.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK455_HPP
#define LEETCODE_TASK455_HPP

#include "../task.hpp"

class Task455 : public Task<455, int(const std::vector<int>&, const std::vector<int>&)> {
public:
    Task455();
    ~Task455() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "分发饼干";
    }
    [[nodiscard]] int solve(const std::vector<int> &g, const std::vector<int> &s) const override;
};

Task455::Task455() {
    this->addTestCase("g = [1,2,3]; s = [1,1]", "1");
    this->addTestCase("g = [1,2]; s = [1,2,3]", "2");
}

int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    auto gb = g.cbegin(), sb = s.cbegin();
    int count = 0;
    while (gb != g.cend() && sb != s.cend()) {
        if (*gb <= *sb) {
            ++gb;
            ++sb;
            ++count;
        } else {
            ++sb;
        }
    }
    return count;
}

int Task455::solve(const std::vector<int> &g, const std::vector<int> &s) const {
    return findContentChildren(const_cast<std::vector<int>&>(g), const_cast<std::vector<int>&>(s));
}

#endif //LEETCODE_TASK455_HPP
