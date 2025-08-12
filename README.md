# Coding Testing Platform

This project aims to implement a platform that can conveniently run programming problems in a local environment. It is implemented in C++ and currently supports writing solutions in the C++ language.

Based on template metaprogramming, programming problems can be imported by implementing `Task` subclasses. The platform supports both LeetCode-style and ACM-style problem inputs. By overriding the `solve` function in a `Task` subclass, algorithmic solutions can be added. Custom test cases can be freely added, and the platform will automatically execute them and verify the results.

#### Usage

Define a `Task` subclass using a macro. In the macro definition, specify the return type and parameter types of the problem in order.

- `#define using_LeetCodeTestCaseReader` indicates that the LeetCode-style input format will be used.
- `#define using_NormalTestResultProcessor` indicates that the program output will be used directly for judging without any additional processing.

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

2. Test cases can be added through the file `tasks/task_input/leetcode_task1.txt`. Different parameters are separated by `;`, and the parameters and the expected return value are separated by `|`.

```c++
nums = [2,7,11,15] ; target = 9 | [0,1]
nums = [3,2,4]     ; target = 6 | [1,2]
nums = [3, 3]      ; target = 6 | [0,1]
```

3. **Override the `solve` method** to write your algorithm:

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

4. **Set up your `main.cpp`** by including the initializer and your task headers. Use the `TASK_MAIN` macro to run one or more tasks in sequence:

```c++
// main.cpp
#include "initialize.h"
#include "tasks/task_impl/include/leetcode_task1.h"
#include "tasks/task_impl/include/leetcode_task2.h"

TASK_MAIN(Task1)
// You can also write TASK_MAIN(Task1, Task2)
```

5. Get the test result.

![result](https://github.com/Ankaichen/leetcode/blob/master/assets/result.png)

#### TestCaseReader

Used to adapt to different input formats. Use `#define using_LeetCodeTestCaseReader` to set the current Task to LeetCode mode, and use `#define using_ACMTestCaseReader` to set the current Task to ACM mode.

**LeetCode Mode Test Case Format:** Different parameters are separated by `;`, parameters and return values are separated by `|`, and lines starting with `#` are treated as comments.

```txt
nums = [2,7,11,15] ; target = 9 | [0,1]
# nums = [3,2,4]     ; target = 6 | [1,2]
nums = [3, 3]      ; target = 6 | [0,1]
```

**ACM Mode Test Case Format:** Content after `>>` represents the input stream, content after `<<` represents the output stream, and `####` is used to separate test cases.

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

Used for post-processing the solution output.

- `#define using_NormalTestResultProcessor` is for standard LeetCode problems.
- `#define using_ACMTestResultProcessor` is for ACM problems.
- `#define using_ListNodeTestResultProcessor` is for LeetCode problems with `ListNode` output.
- `#define using_UnorderedTestResultProcessor_i` is for problems where the output order is arbitrary.