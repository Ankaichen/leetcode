/**
 ******************************************************************************
 * @file           : leetcode_task912.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-7
 ******************************************************************************
 */

#include "../include/leetcode_task912.h"

void bubbleSort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        bool flag = false;
        for (int j = 0; j < nums.size() - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

void selectSort(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        int min_v = nums[i], min_i = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < min_v) {
                min_v = nums[j];
                min_i = j;
            }
        }
        std::swap(nums[i], nums[min_i]);
    }
}

void insertSort(std::vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
        int j = i - 1, temp = nums[i];
        for (; j >= 0; --j) {
            if (nums[j] > temp)
                nums[j + 1] = nums[j];
            else
                break;
        }
        nums[j + 1] = temp;
    }
}

void binaryInsertSort(std::vector<int> &nums) {
    auto binarySearch = [&nums](int left, int right, int target) -> int {
        while (left <= right) {                   // 此处的循环条件是 <=
            int mid = left + (right - left) / 2;  // 是因为left和right是左闭右闭
            if (nums[mid] < target)
                left = mid + 1;  // 要处理总长度为1的情况
            else if (nums[mid] > target)
                right = mid - 1;  // 也包括几轮二分后,剩余长度为1的情况
            else
                return mid;
        }
        return left;
    };
    for (int i = 1; i < nums.size(); ++i) {
        int temp = nums[i];
        int target = binarySearch(0, i - 1, temp);
        for (int j = i - 1; j >= target; --j) nums[j + 1] = nums[j];
        nums[target] = temp;
    }
}

void mergeSort(std::vector<int> &nums) {
    std::vector<int> temp(nums.size(), 0);
    auto inner = [&nums, &temp](auto &self, int left, int right) -> void {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        self(self, left, mid);
        self(self, mid + 1, right);
        int i1 = left, i2 = mid + 1;
        for (int i = left; i <= right; ++i) {
            if (i1 > mid || (i2 <= right && nums[i1] >= nums[i2])) {
                temp[i] = nums[i2++];
            } else {
                temp[i] = nums[i1++];
            }
        }
        for (int i = left; i <= right; ++i) nums[i] = temp[i];
    };
    inner(inner, 0, nums.size() - 1);
}

void heapSort(std::vector<int> &nums) {
    auto adjustHeap = [&nums](int start, int end) -> void {
        for (int i = start * 2 + 1; i < end; i = start * 2 + 1) {
            if (i + 1 < end && nums[i + 1] > nums[i]) ++i;
            if (nums[start] < nums[i]) {
                std::swap(nums[start], nums[i]);
                start = i;
            } else
                break;
        }
    };
    auto initHeap = [&nums, &adjustHeap]() -> void {
        for (int i = nums.size() / 2 - 1; i >= 0; --i) {
            adjustHeap(i, nums.size());
        }
    };
    initHeap();
    for (int i = nums.size() - 1; i > 0; --i) {
        std::swap(nums[0], nums[i]);
        adjustHeap(0, i);
    }
}

void quickSort(std::vector<int> &nums) {
    auto partition = [&nums](int left, int right) -> int {
        std::swap(nums[left], nums[left + (right - left) / 2]);
        int pivot = nums[left];
        while (left < right) {
            for (; left < right && nums[right] >= pivot; --right);
            nums[left] = nums[right];
            for (; left < right && nums[left] <= pivot; ++left);
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    };
    auto inner = [&nums, &partition](auto &self, int left, int right) -> void {
        if (left >= right) return;
        int pivot = partition(left, right);
        self(self, left, pivot - 1);
        self(self, pivot + 1, right);
    };
    inner(inner, 0, nums.size() - 1);
}

std::vector<int> LeetcodeTask912::solve(const std::vector<int> &nums) const {
    quickSort(const_cast<std::vector<int> &>(nums));
    return nums;
}

// bubbleSort        3560 ms  3555 ms  3628 ms
// selectSort        2697 ms  2701 ms  2664 ms
// insertSort        1215 ms  1233 ms  1246 ms
// binaryInsertSort 952.8 ms 963.6 ms 985.7 ms
// mergeSort        6.283 ms 6.423 ms  6.03 ms
// heapSort         7.541 ms 7.482 ms 7.405 ms
// quickSort         4.93 ms 4.579 ms 4.748 ms
// std::sort        1.973 ms 1.963 ms 1.988 ms