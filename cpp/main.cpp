#include <iostream>
#include <vector>

#include "task/impl//task1.hpp"

int main() {
    system("chcp 65001 > nul");

    Task1 task1;
    std::cout << task1.title() << std::endl;

    std::vector<bool> result = task1.test();
    std::vector<TestCase> testCase = task1.getTestCase();
    for (int i = 0; i < result.size(); ++i) {
        std::cout << testCase[i].input << "\t->\t" << std::boolalpha << result[i] << std::endl;
    }

    return 0;
}
