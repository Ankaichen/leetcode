/**
 ******************************************************************************
 * @file           : leetcode_task88.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-13
 ******************************************************************************
 */

#include "../include/leetcode_task88.h"

void merge3(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // 反向双指针 从后往前遍历 避免覆盖nums1中数据
    for (int i = m + n - 1, j = m - 1, k = n - 1; i >= 0; --i) {
        if (k < 0 || (j >= 0 && nums1[j] >= nums2[k]))
            nums1[i] = nums1[j--];
        else if (j < 0 || (k >= 0 && nums1[j] < nums2[k]))
            nums1[i] = nums2[k--];
    }
}

void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    // 正向双指针 需要开辟一块儿内存 保存合并后的数据
    std::vector<int> result(nums1.begin(), nums1.begin() + m);
    std::swap(result, nums1);
    for (int i = 0, j = 0, k = 0; i < m + n; ++i) {
        if (k >= n || (j < m && nums1[j] <= nums2[k]))
            result[i] = nums1[j++];
        else if (j >= m || (k < n && nums1[j] > nums2[k]))
            result[i] = nums2[k++];
    }
    std::swap(result, nums1);
}

void merge1(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
    std::sort(nums1.begin(), nums1.end());
}

std::vector<int> LeetcodeTask88::solve(const std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) const {
    merge3(const_cast<std::vector<int>&>(nums1), m, const_cast<std::vector<int>&>(nums2), n);
    return nums1;
}