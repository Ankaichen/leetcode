/**
  ******************************************************************************
  * @file           : task977.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-21
  ******************************************************************************
  */

#ifndef LEETCODE_TASK977_HPP
#define LEETCODE_TASK977_HPP

#include "../task.hpp"

class Task977 : public Task<977, std::vector<int>(const std::vector<int> &)> {
public:
    Task977();

    ~Task977() noexcept override = default;

    std::string title() const override {
        return "有序数组的平方";
    }

    std::vector<int> solve(const std::vector<int> &nums) const override;
};

Task977::Task977() {
    this->addTestCase("nums = [-4,-1,0,3,10]", "[0,1,9,16,100]");
    this->addTestCase("nums = [-7,-3,2,3,11]", "[4,9,9,49,121]");
}

std::vector<int> sortedSquares1(const std::vector<int> &nums) {
    std::vector<int> result_vec(nums.size(), 0);
    auto mid = nums.cbegin();
    for (; mid != nums.cend() && *mid < 0; ++mid);
    auto rmid = std::reverse_iterator(mid);
    auto res = result_vec.begin();
    while (mid != nums.cend() && rmid != nums.crend()) {
        if (*mid > -(*rmid)) {
            *res = (*rmid) * (*rmid);
            ++rmid;
        } else {
            *res = (*mid) * (*mid);
            ++mid;
        }
        ++res;
    }
    while (mid != nums.cend()) {
        *res = (*mid) * (*mid);
        ++mid;
        ++res;
    }
    while (rmid != nums.crend()) {
        *res = (*rmid) * (*rmid);
        ++rmid;
        ++res;
    }
    return result_vec;
}

std::vector<int> sortedSquares2(const std::vector<int> &nums) {
    std::vector<int> result_vec(nums.size(), 0);
    int left = 0, right = nums.size() - 1;
    auto res_iter = result_vec.rbegin();
    while (left <= right) {
        if ((-nums[left]) > nums[right]) {
            *res_iter = nums[left] * nums[left];
            ++left;
        } else {
            *res_iter = nums[right] * nums[right];
            --right;
        }
        ++res_iter;
    }
    return result_vec;
}

std::vector<int> Task977::solve(const std::vector<int> &nums) const {
    return sortedSquares2(nums);
}

#endif //LEETCODE_TASK977_HPP
