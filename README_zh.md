# 力扣测试平台

## C++

C++版本基于模板元编程实现，通过实现`Task`子类引入力扣题目，重写其中的`solve`函数加入算法的具体实现，可自由加入字符串格式的测试用例，并自动运行。

使用方法

1. 定义**`Task`模板类**的子类，模板参数分别为题目编号和题目参数与返回值

```c++
// task/impl/task1.hpp
class Task1 : public Task<1, std::vector<int>(const std::vector<int> &, int)> {
public:
    Task1();
    ~Task1() noexcept override = default;
    [[nodiscard]] std::string title() const override  {
        return "两数之和";
    }
    [[nodiscard]] std::vector<int> solve(const std::vector<int> &nums, int target) const override;
};
```

2. 通过**`addTestCase`函数**加入测试用例，不同参数间使用`;`分隔。

```c++
// task/impl/task1.hpp
Task1::Task1() {
    this->addTestCase("nums = [2,7,11,15]; target = 9", "[0,1]");
    this->addTestCase("nums = [3,2,4]; target = 6", "[1,2]");
    this->addTestCase("nums = [3, 3]; target = 6", "[0,1]");
    this->addTestCase("nums = [3, 3]; target = 6", "[1]");
}
```

3. 重写父类的**`solve`函数**，在其中写题解

```c++
// task/impl/task1.hpp
std::vector<int> Task1::solve(const std::vector<int> &nums, int target) const {
    int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}
```

4. 在**main函数**中导入初始化头文件`initialize.h`和对应的题目头文件`task/impl/task1.hpp`，使用`TASK_MAIN`即可运行，`TASK_MAIN`内可传入多个题目类，可依次运行

```c++
// main.cpp
#include "initialize.h"
#include "task/impl/task1.hpp"
#include "task/impl/task2.hpp"

TASK_MAIN(Task1)
// 可以写为 TASK_MAIN(Task1, Task2)
```

5. 得到测试结果

![image-20250419211906077](https://github.com/Ankaichen/leetcode/blob/master/assets/image-20250419211906077.png)