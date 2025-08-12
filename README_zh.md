# 编程题运行平台

本项目旨在实现一个能够在本地环境便捷运行编程题目的平台，由C++实现，目前可支持C++语言编写题解。

基于模板元编程实现，通过实现`Task`子类导入编程题，可支持Leetcode格式以及ACM格式的题目输入，通过重写`Task`子类的`solve`函数可加入算法的题解，可自由加入测试用例，并自动运行并判断运行结果。

#### 使用方法

1. 通过宏定义`Task`子类，宏定义中依次写入该题的返回值以及参数类型。
   - `#define using_LeetCodeTestCaseReader`代表使用Leetcode格式输入
   - `#define using_NormalTestResultProcessor`代表运行结果不做处理，直接进入判题阶段。

```c++
// tasks/task_impl/include/leetcode_task1.h
#ifndef LEETCODE_LEETCODE_TASK1_H
#define LEETCODE_LEETCODE_TASK1_H

#define using_LeetCodeTestCaseReader
#define using_NormalTestResultProcessor

#include "../../core/macro/define_task.h"

DEFINE_TASK(LeetcodeTask1, "1.两数之和", std::vector<int>, const std::vector<int> &, int);

#include "../../core/macro/end_define_task.h"

#endif  // LEETCODE_LEETCODE_TASK1_H
```

2. 通过`tasks/task_input/leetcode_task1.txt`文件加入测试用例，不同参数间使用`;`分隔，参数与返回值间使用`|`分隔。

```txt
nums = [2,7,11,15] ; target = 9 | [0,1]
nums = [3,2,4]     ; target = 6 | [1,2]
nums = [3, 3]      ; target = 6 | [0,1]
```

3. 重写**`solve`函数**，在其中写题解

```c++
// tasks/task_impl/source/leetcode_task1.cpp
#include "../include/leetcode_task1.h"
static std::vector<int> twoSum2(const std::vector<int> &nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        auto pair_i = map.find(nums[i]);
        if (pair_i != map.end()) {
            return {pair_i->second, i};
        } else {
            map.insert(std::make_pair(target - nums[i], i));
        }
    }
    return {-1, -1};
}
std::vector<int> LeetcodeTask1::solve(const std::vector<int> &nums, int target) const {
  return twoSum2(nums, target);
}
```

4. 在**main函数**中导入初始化头文件`initialize.h`和对应的题目头文件`tasks/task_impl/include/leetcode_task1.h`，使用`TASK_MAIN`即可运行，`TASK_MAIN`内可传入多个题目类，可依次运行

```c++
// main.cpp
#include "initialize.h"
#include "tasks/task_impl/include/leetcode_task1.h"
#include "tasks/task_impl/include/leetcode_task2.h"

TASK_MAIN(Task1)
// 可以写为 TASK_MAIN(Task1, Task2)
```

5. 得到测试结果

![result](https://github.com/Ankaichen/leetcode/blob/master/assets/result.png)

#### TestCaseReader

用于适配不同格式的输入，通过`#define using_LeetCodeTestCaseReader`可设置当前Task为Leetcode模式，通过`#define using_ACMTestCaseReader`可设置当前Task为ACM模式。

**Leetcode模式的测试用例格式：**不同参数间使用`;`分隔，参数与返回值间使用`|`分隔，使用`#`注释当前行用例。

```txt
nums = [2,7,11,15] ; target = 9 | [0,1]
# nums = [3,2,4]     ; target = 6 | [1,2]
nums = [3, 3]      ; target = 6 | [0,1]
```

**ACM模式的测试用例格式：**`>>`后表示输入流内容，`<<`后表示输出流内容，`####`用于分隔测试用例。

```txt
>>
6 1
2 2 3 1 5 2
2 3 1 5 4 3
<<
5
########################
>>
6 1
1 2 3 1 4 2
2 2 1 4 4 3
<<
4
```

#### TestResultProcessor

用于对题解输出结果的二次处理

- `#define using_NormalTestResultProcessor`用于一般的Leetcode题目
- `#define using_ACMTestResultProcessor`用于ACM题目
- `#define using_ListNodeTestResultProcessor`用于以`ListNode`为输出的Leetcode题目
- `#define using_UnorderedTestResultProcessor_i`用于输出顺序任意的题目