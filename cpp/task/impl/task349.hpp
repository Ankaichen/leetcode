/**
  ******************************************************************************
  * @file           : task349.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK349_HPP
#define LEETCODE_TASK349_HPP

#include "../task.hpp"

#include <set>

class Task349 : public Task<349, std::set<int>(const std::vector<int> &, const std::vector<int> &)> {
public:
    Task349();

    ~Task349() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "两个数组的交集";
    }

    [[nodiscard]] std::set<int> solve(const std::vector<int> &num1, const std::vector<int> &num2) const override;
};

Task349::Task349() {
    this->addTestCase("nums1 = [1,2,2,1]; nums2 = [2,2]", "{2}");
    this->addTestCase("nums1 = [4,9,5]; nums2 = [9,4,9,8,4]", "{9,4}");
}

std::vector<int> intersection(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    std::set set1(nums1.begin(), nums1.end());
    std::set set2(nums2.begin(), nums2.end());
    std::vector<int> result;
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(result, result.begin()));
    return result;
}

std::set<int> Task349::solve(const std::vector<int> &num1, const std::vector<int> &num2) const {
    std::vector<int> result = intersection(num1, num2);
    return {result.cbegin(), result.cend()};
}

#endif //LEETCODE_TASK349_HPP
