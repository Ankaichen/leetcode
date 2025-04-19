#include <iostream>
#include <vector>
#include <list>
#include <map>

#include "task/impl/task1.hpp"
#include "task/task_runner.hpp"

int main() {

    TaskRunner<Task1>::getInstance().run();

//    std::getchar();

    return 0;
}
