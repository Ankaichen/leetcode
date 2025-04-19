# LeetCode Testing Platform

## C++

The C++ version is implemented using template metaprogramming. By creating a subclass of `Task`, you can integrate any LeetCode problem: override its `solve` method to provide your algorithm, add test cases as formatted strings, and have them run automatically.

Usage

1. **Define a subclass** of the `Task` template. The first template parameter is the problem number; the second is the function signature (parameter types and return type).

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

2. **Add test cases** in the constructor using `addTestCase`. Separate each parameter assignment with `;`.

```c++
// task/impl/task1.hpp
Task1::Task1() {
    this->addTestCase("nums = [2,7,11,15]; target = 9", "[0,1]");
    this->addTestCase("nums = [3,2,4]; target = 6", "[1,2]");
    this->addTestCase("nums = [3, 3]; target = 6", "[0,1]");
    this->addTestCase("nums = [3, 3]; target = 6", "[1]");
}
```

3. **Override the `solve` method** to write your algorithm:

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

4. **Set up your `main.cpp`** by including the initializer and your task headers. Use the `TASK_MAIN` macro to run one or more tasks in sequence:

```c++
// main.cpp
#include "initialize.h"
#include "task/impl/task1.hpp"
#include "task/impl/task2.hpp"

TASK_MAIN(Task1)
// You can also write TASK_MAIN(Task1, Task2)
```

5. Get the test result.

![image-20250419211906077](https://github.com/Ankaichen/leetcode/blob/master/assets/image-20250419211906077.png)