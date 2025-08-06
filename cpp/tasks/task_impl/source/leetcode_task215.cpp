/**
 ******************************************************************************
 * @file           : leetcode_task215.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-6
 ******************************************************************************
 */

#include "../include/leetcode_task215.h"

static int findKthLargest1(std::vector<int>& nums, int k) {
    // 不满足时间复杂度 O(n)
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

static int partition(std::vector<int>& nums, int left, int right) {
    std::swap(nums[left], nums[left + (right - left) / 2]);  // 将中间值作为枢轴 避免快排最坏情况
    int pivot = nums[left];
    while (left < right) {
        while (left < right && pivot <= nums[right]) {
            --right;
        }
        nums[left] = nums[right];
        while (left < right && pivot >= nums[left]) {
            ++left;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}

static int findKthLargest2(std::vector<int>& nums, int k) {
    // 快排思路 每次确定一个位置 目标范围减少一半 直到找到目标位置
    // 时间复杂度 O(nlogk)
    int left = 0, right = nums.size() - 1;
    int target = nums.size() - k, pivot;
    while (left < right && (pivot = partition(nums, left, right)) != target) {
        if (pivot < target) {
            left = pivot + 1;
        } else {
            right = pivot - 1;
        }
    }
    return nums[target];
}

static void adjustHeap(std::vector<int>& heap, int from = 1) {
    --from;
    for (int i = 2, k = 1; from + i < heap.size(); i = k * 2) {
        if (from + i + 1 < heap.size() && heap[from + i] < heap[from + i + 1]) i = i + 1;
        if (heap[from + i] < heap[from + k]) std::swap(heap[from + i], heap[from + k]);
        k = i;
    }
}

static void initHeap(std::vector<int>& heap, int from) {
    for (int i = heap.size() - 1; i >= from; --i) {
        adjustHeap(heap, i);
    }
}

static int findKthLargest3(std::vector<int>& nums, int k) {
    // 堆排思路 维护一个大小为k的小根堆 遍历数组 不断替换小根堆中的最小值
    // 时间复杂度 O(nlogk)
    int target = nums.size() - k;
    initHeap(nums, target);
    std::cout << target << std::endl;
    for (auto i : nums) std::cout << i << ", ";
    std::cout << std::endl;
    for (int i = 0; i < target; ++i) {
        if (nums[i] > nums[target]) {
            std::swap(nums[i], nums[target]);
            adjustHeap(nums, target);
        }
    }
    return nums[target];
}

int LeetcodeTask215::solve(const std::vector<int>& nums, int k) const { return findKthLargest3(const_cast<std::vector<int>&>(nums), k); }