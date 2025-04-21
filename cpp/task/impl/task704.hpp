/**
  ******************************************************************************
  * @file           : task704.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK704_HPP
#define LEETCODE_TASK704_HPP

#include "../task.hpp"

class Task704 : public Task<704, int(const std::vector<int> &, int)> {
public:
    Task704();

    ~Task704() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "二分查找";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums, int target) const override;
};

Task704::Task704() {
    this->addTestCase("nums = [-1,0,3,5,9,12]; target = 9", "4");
    this->addTestCase("nums = [-1,0,3,5,9,12]; target = 2", "-1");
}

int search1(const std::vector<int> &nums, int target) {
    int low = 0, high = static_cast<int>(nums.size() - 1);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int Task704::solve(const std::vector<int> &nums, int target) const {
    return search1(nums, target);
}

#endif //LEETCODE_TASK704_HPP
