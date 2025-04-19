#include <iostream>
#include <vector>

#include "task/impl/task1.hpp"
#include "task/task_runner.hpp"

int main() {
    system("chcp 65001 > nul");

    TaskRunner<Task1>::getInstance().run();

    std::getchar();

    return 0;
}
