#include <iostream>
#include <vector>

#include "task/impl//task1.hpp"

int main() {
    system("chcp 65001 > nul");

//    std::string str{"[2,7,11,15]"};

//    Parse::parseType<const std::vector<int>>()

//    std::cout << std::is_arithmetic_v<const int> << std::endl;

    Task1 task1;
    std::cout << task1.title() << std::endl;

    task1.test();

    return 0;
}
