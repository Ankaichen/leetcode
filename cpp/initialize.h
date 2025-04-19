/**
  ******************************************************************************
  * @file           : initialize.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-19
  ******************************************************************************
  */

#ifndef LEETCODE_INITIALIZE_H
#define LEETCODE_INITIALIZE_H

#include "task/task_runner.hpp"

template<typename... Tasks>
void runTasks() {
    static_assert((TypeTraits::is_task_v<Tasks> && ...));
    (TaskRunner<Tasks>::getInstance().run(), ...);
}

#define TASK_MAIN(...)       \
int main() {                 \
    runTasks<__VA_ARGS__>(); \
    return 0;                \
}

#endif //LEETCODE_INITIALIZE_H
