/**
  ******************************************************************************
  * @file           : task27.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK27_HPP
#define LEETCODE_TASK27_HPP

#include "../task.hpp"

class Task27 : public Task<27, int(const std::vector<int> &, int)> {
public:
    Task27();

    ~Task27() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "移除元素";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums, int val) const override;
};

Task27::Task27() {
    this->addTestCase("nums = [3,2,2,3]; val = 3", "2");
    this->addTestCase("nums = [0,1,2,2,3,0,4,2]; val = 2", "5");
}

int removeElement1(std::vector<int> &nums, int val) {
    int low = 0, high = 0;
    for (; high < nums.size(); ++high) {
        if (nums[high] != val) {
            nums[low++] = nums[high];
        }
    }
    return low;
}

int Task27::solve(const std::vector<int> &nums, int val) const {
    return removeElement1(const_cast<std::vector<int> &>(nums), val);
}

#endif //LEETCODE_TASK27_HPP
