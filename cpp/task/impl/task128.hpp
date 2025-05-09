/**
  ******************************************************************************
  * @file           : task128.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-30
  ******************************************************************************
  */

#ifndef LEETCODE_TASK128_HPP
#define LEETCODE_TASK128_HPP

#include "../task.hpp"

class Task128 : public Task<128, int(const std::vector<int> &)> {
public:
    Task128();

    ~Task128() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "最长连续序列";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums) const override;
};

Task128::Task128() {
    this->addTestCase("nums = [100,4,200,1,3,2]", "4");
    this->addTestCase("nums = [0,3,7,2,5,8,4,6,0,1]", "9");
    this->addTestCase("nums = [1,0,1,2]", "3");
}

int longestConsecutive1(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (int i: nums) {
        set.insert(i);
    }
    int maxContinue = 0;
    for (int i: set) {
        if (set.find(i - 1) != set.end())
            continue;
        int curContinue = 1;
        int curNum = i;
        while (set.find(curNum + 1) != set.end()) {
            ++curContinue;
            ++curNum;
        }
        maxContinue = std::max(maxContinue, curContinue);
    }
    return maxContinue;
}

int longestConsecutive2(const std::vector<int>& nums) {
    UnionFind<int> uf;
    for (int i : nums) {
        uf.insert(i);
    }
    for (int i : nums) {
        uf.union_value(i, i + 1);
    }
    int result = 0;
    for (int i : nums) {
        result = std::max(static_cast<int>(uf.union_size(i)), result);
    }
    return result;
}

int Task128::solve(const std::vector<int> &nums) const {
    return longestConsecutive2(nums);
}

#endif //LEETCODE_TASK128_HPP
