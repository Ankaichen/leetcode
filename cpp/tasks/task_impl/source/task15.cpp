/**
  ******************************************************************************
  * @file           : task15.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task15.h"

Task15::Task15() {
    this->addTestCase("nums = [-1,0,1,2,-1,-4]", "{{-1,-1,2},{-1,0,1}}");
    this->addTestCase("nums = [0,1,1]", "{}");
    this->addTestCase("nums = [0,0,0]", "{{0,0,0}}");
    this->addTestCase("nums = [0,0,0,0]", "{{0,0,0}}");
}

static std::vector<std::vector<int>> threeSum1(const std::vector<int> &nums) {
    // 超出时间限制
    std::set<std::multiset<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int z = j + 1; z < nums.size(); ++z) {
                if (nums[i] + nums[j] + nums[z] == 0) {
                    std::multiset<int> tempSet{nums[i], nums[j], nums[z]};
                    result.insert(tempSet);
                }
            }
        }
    }
    std::vector<std::vector<int>> resultVec;
    for (auto &s1: result) {
        resultVec.emplace_back(s1.begin(), s1.end());
    }
    return resultVec;
}

static std::vector<std::vector<int>> threeSum2(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    // 存储 b 检索 -(a+c)
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break; // 不可能有等于0的情况
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 如果一个数已经出现过，去重
        std::unordered_set<int> set; // 用于存储b
        for (int k = i + 1; k < nums.size(); ++k) {
            // 去重b=c时的b和c
            if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2])
                continue;
            int target = -(nums[i] + nums[k]);
            auto iter = set.find(target);
            if (iter != set.end()) { // 如果有对应的b 则nums[k]作为c
                result.push_back({nums[i], target, nums[k]});
                set.erase(iter);
            } else { // 如果没有对应的b 则nums[k]保存为b
                set.insert(nums[k]);
            }
        }
    }
    return result;
}

static std::vector<std::vector<int>> threeSum3(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    // 双指针
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = static_cast<int>(nums.size()) - 1;
        while (right > left) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                --right;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                ++left;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                for (++left; right > left && nums[left] == nums[left - 1]; ++left);
                for (--right; right > left && nums[right] == nums[right + 1]; --right);
            }
        }

    }
    return result;
}

std::multiset<std::multiset<int>> Task15::solve(const std::vector<int> &nums) const {
    std::vector<std::vector<int>> vecResult = threeSum3(const_cast<std::vector<int> &>(nums));
    std::multiset<std::multiset<int>> setResult;
    for (const auto &v: vecResult) {
        std::multiset<int> tempSet(v.cbegin(), v.cend());
        setResult.insert(tempSet);
    }
    return setResult;
}