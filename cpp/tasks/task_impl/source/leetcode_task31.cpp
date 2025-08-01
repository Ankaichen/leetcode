/**
  ******************************************************************************
  * @file           : leetcode_task31.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task31.h"

static void nextPermutation1(std::vector<int>& nums) {
    if (nums.size() <= 1) return;
    for (int i = nums.size() - 2; i >= 0; --i) {
        // i + 1 到 nums.size() 是从小到大排序的
        // 也就是说 从 i + 1 找第一个大于 nums[i] 的数与 nums[i] 交换 就是最终结果
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] > nums[i]) {
                std::swap(nums[j], nums[i]);
                return;
            }
        }
        // 没有的话 将 nums[i] 放到最后 保证有序
        int temp = nums[i];
        for (int j = i + 1; j < nums.size(); ++j) {
            nums[j - 1] = nums[j];
        }
        nums[nums.size() - 1] = temp;
    }
    // 没有字典序更大的排列 此时已完成插入排序 直接返回
}

static void nextPermutation2(std::vector<int>& nums) {
    if (nums.size() <= 1) return;
    // 从后向前找第一个非递增的数 能够保证后面的数无法得到更大的排列
    // 同时保证后面的数是降序
    int i = nums.size() - 2;
    for (; i >= 0 && nums[i] >= nums[i + 1]; --i);
    if (i >= 0) {
        int j = nums.size() - 1;
        for (; j > i && nums[j] <= nums[i]; --j);
        std::swap(nums[i], nums[j]);
    }
    // 后面的数整体反转
    std::reverse(nums.begin() + 1 + i, nums.end());
}

std::vector<int> LeetcodeTask31::solve(const std::vector<int> &nums) const {
    nextPermutation2(const_cast<std::vector<int>&>(nums));
    return nums;
}