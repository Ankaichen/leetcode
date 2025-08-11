/**
 ******************************************************************************
 * @file           : leetcode_task33.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-11
 ******************************************************************************
 */

#include "../include/leetcode_task33.h"

static int search3(std::vector<int>& nums, int target) {
    // 通过判断顺序范围 每次可以排除一半数据
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {                         // 左侧为顺序的
            if (nums[left] <= target && target < nums[mid]) {  // 判断目标值是否在左侧
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {                                                // 右侧是顺序的
            if (nums[mid] < target && target <= nums[right]) {  // 判断目标值是否在右侧
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

static int search2(std::vector<int>& nums, int target) {
    // 首先使用二分法找到原始数组的起始点
    auto findBegin = [&nums](auto& self, int left, int right) -> int {
        if (left == right) return right;
        if (left + 1 == right && nums[left] > nums[right]) return right;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {  // 通过判断两端的大小 可知左右哪段是无序的 分界点一定在无序的那段儿
            return self(self, mid, right);
        } else {
            return self(self, left, mid);
        }
    };
    // 已知原始数组的起始点后 可以得到旋转后数组与原始数组间的索引计算关系
    // 根据计算关系 将原始索引修改为现在的索引 从而使用二分查找求解
    auto binarySearch = [&nums](int target, std::function<int(int)> indexConvert) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cvtMid = indexConvert(mid);
            if (nums[cvtMid] == target) {
                return cvtMid;
            } else if (nums[cvtMid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    };
    int startPos = findBegin(findBegin, 0, nums.size() - 1);
    return binarySearch(target, [startPos, &nums](int index) -> int { return (index + startPos) % nums.size(); });
}

static int search1(std::vector<int>& nums, int target) {
    auto iter = std::find(nums.begin(), nums.end(), target);
    if (iter == nums.end())
        return -1;
    else
        return std::distance(nums.begin(), iter);
}

int LeetcodeTask33::solve(const std::vector<int>& nums, int target) const { return search3(const_cast<std::vector<int>&>(nums), target); }