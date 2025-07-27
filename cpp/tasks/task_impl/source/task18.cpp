/**
  ******************************************************************************
  * @file           : task18.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task18.h"

Task18::Task18() {
    this->addTestCase("nums = [1,0,-1,0,-2,2]; target = 0", "{{-2,-1,1,2},{-2,0,0,2},{-1,0,0,1}}");
    this->addTestCase("nums = [2,2,2,2,2]; target = 8", "{{2,2,2,2}}");
    this->addTestCase("nums = [1,-2,-5,-4,-3,3,3,5]; target = -11", "{{-5,-4,-3,1}}");
    this->addTestCase("nums = [1000000000,1000000000,1000000000,1000000000]; target = 0", "{}");
}

static std::vector<std::vector<int>> fourSum1(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > target && nums[i] >= 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = static_cast<int>(nums.size()) - 1;
            while (left < right) {
                if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] < target) {
                    ++left;
                } else if (static_cast<long>(nums[i]) + nums[j] + nums[left] + nums[right] > target) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    for (++left; left < right && nums[left] == nums[left - 1]; ++left);
                    for (--right; left < right && nums[right] == nums[right + 1]; --right);
                }
            }
        }
    }
    return result;
}

std::multiset<std::multiset<int>> Task18::solve(const std::vector<int> &nums, int target) const {
    std::vector<std::vector<int>> vecResult = fourSum1(const_cast<std::vector<int> &>(nums), target);
    std::multiset<std::multiset<int>> setResult;
    for (const auto &v: vecResult) {
        std::multiset<int> tempSet(v.cbegin(), v.cend());
        setResult.insert(tempSet);
    }
    return setResult;
}