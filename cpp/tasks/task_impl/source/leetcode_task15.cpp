/**
 ******************************************************************************
 * @file           : leetcode_task15.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-6-19
 ******************************************************************************
 */

#include "../include/leetcode_task15.h"

static std::vector<std::vector<int>> threeSum1(const std::vector<int> &nums) {
    // 暴力搜索 超出时间限制
    std::set<std::multiset<int>> result;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            for (int z = j + 1; z < nums.size(); ++z) {  // 遍历所有可能的组合
                if (nums[i] + nums[j] + nums[z] == 0) {  // 保存符合的 使用set去重
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
    // 根据-(a+c)=b 仅遍历a c 使用a c计算b 从而去除一层循环
    // 第一层循环i 遍历a
    // 第二层循环k 遍历c 同时计算b
    std::sort(nums.begin(), nums.end());  // 排序 方便剪枝
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break;                         // 不可能有等于0的情况
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // 如果一个数已经出现过，去重
        std::unordered_set<int> set;                    // 用于存储b 这里nums[i]是a b是根据a c计算得到的
        for (int k = i + 1; k < nums.size(); ++k) {
            // 去重b=c时的b和c 这种情况是 a c c c 遍历前两个c组成一组结果后 如果再遍历第三个c 就会在set中存储重复的值
            // 注意k > i + 2 即此处的剪枝不能影响a 只看a后面的值
            if (k > i + 2 && nums[k] == nums[k - 1] && nums[k - 1] == nums[k - 2]) continue;
            int target = -(nums[i] + nums[k]);  // 计算这组a c对应的b
            auto iter = set.find(target);       // 找b
            if (iter != set.end()) {            // 如果有对应的b 则nums[k]作为c
                result.push_back({nums[i], target, nums[k]});
                set.erase(iter);
            } else {  // 如果没有对应的b 则nums[k]保存为b
                set.insert(nums[k]);
            }
        }
    }
    return result;
}

static std::vector<std::vector<int>> threeSum3(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    // 双指针 即循环遍历a 对于每个a 使用双指针寻找b c
    // 由于双指针不存在集合存取操作 因此效率更高
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break;  // 这里的剪枝策略和上面相同
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = static_cast<int>(nums.size()) - 1;
        while (right > left) {  // 双指针寻找合适的b c
            if (nums[i] + nums[left] + nums[right] > 0) {
                --right;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                ++left;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                // 这里是处理存在多组b c的情况 在找到一组后 同时移动双指针 修改为和刚刚不同的情况 避免重复
                for (++left; right > left && nums[left] == nums[left - 1]; ++left);
                for (--right; right > left && nums[right] == nums[right + 1]; --right);
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> LeetcodeTask15::solve(const std::vector<int> &nums) const {
    return threeSum3(const_cast<std::vector<int> &>(nums));
}