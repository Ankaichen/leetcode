// #include "initialize.h"
// #include "tasks/task_impl/include/task1.h"
// #include "tasks/task_impl/include/task2.h"
// #include "tasks/task_impl/include/task3.h"
// #include "tasks/task_impl/include/task7.h"
// #include "tasks/task_impl/include/task15.h"
// #include "tasks/task_impl/include/task17.h"
// #include "tasks/task_impl/include/task18.h"
// #include "tasks/task_impl/include/task19.h"
// #include "tasks/task_impl/include/task24.h"
// #include "tasks/task_impl/include/task27.h"
// #include "tasks/task_impl/include/task31.h"
// #include "tasks/task_impl/include/task39.h"
// #include "tasks/task_impl/include/task40.h"
// #include "tasks/task_impl/include/task59.h"
// #include "tasks/task_impl/include/task62.h"
// #include "tasks/task_impl/include/task63.h"
// #include "tasks/task_impl/include/task70.h"
// #include "tasks/task_impl/include/task77.h"
// #include "tasks/task_impl/include/task96.h"
// #include "tasks/task_impl/include/task128.h"
// #include "tasks/task_impl/include/task130.h"
// #include "tasks/task_impl/include/task142.h"
// #include "tasks/task_impl/include/task151.h"
// #include "tasks/task_impl/include/task202.h"
// #include "tasks/task_impl/include/task203.h"
// #include "tasks/task_impl/include/task206.h"
// #include "tasks/task_impl/include/task209.h"
// #include "tasks/task_impl/include/task216.h"
// #include "tasks/task_impl/include/task242.h"
// #include "tasks/task_impl/include/task290.h"
// #include "tasks/task_impl/include/task343.h"
// #include "tasks/task_impl/include/task344.h"
// #include "tasks/task_impl/include/task349.h"
// #include "tasks/task_impl/include/task383.h"
// #include "tasks/task_impl/include/task416.h"
// #include "tasks/task_impl/include/task454.h"
// #include "tasks/task_impl/include/task455.h"
// #include "tasks/task_impl/include/task509.h"
// #include "tasks/task_impl/include/task541.h"
// #include "tasks/task_impl/include/task556.h"
// #include "tasks/task_impl/include/task704.h"
// #include "tasks/task_impl/include/task746.h"
// #include "tasks/task_impl/include/task977.h"
// #include "tasks/task_impl/include/task1049.h"
// #include "tasks/task_impl/include/task2416.h"

// TASK_MAIN(
//         Task1,
//         Task2,
//         Task3,
//         Task7,
//         Task15,
//         Task17,
//         Task18,
//         Task19,
//         Task24,
//         Task27,
//         Task31,
//         Task39,
//         Task40,
//         Task59,
//         Task62,
//         Task63,
//         Task70,
//         Task77,
//         Task96,
//         Task128,
//         Task130,
//         Task142,
//         Task151,
//         Task202,
//         Task203,
//         Task206,
//         Task209,
//         Task216,
//         Task242,
//         Task290,
//         Task343,
//         Task344,
//         Task349,
//         Task383,
//         Task416,
//         Task454,
//         Task455,
//         Task509,
//         Task541,
//         Task556,
//         Task704,
//         Task746,
//         Task977,
//         Task1049,
//         Task2416
//)

#include <cassert>
#include <iostream>
#include <vector>

// #include "./tasks/core/test_case_reader.hpp"
#include "./utils/parameter_type_traits.hpp"

template<typename T, typename Y, int A>
class Test1 {
public:
    virtual ~Test1() = 0;
};
template<typename T, typename Y, int A>
Test1<T, Y, A>::~Test1() = default;

class Test2 : public Test1<int, float, 2> {
public:
    ~Test2() override = default;
};

template<typename T>
class is_base_test : public std::false_type {};

template<typename T, typename Y, int A>
class is_base_test<Test1<T, Y, A>> : public std::true_type {};

template<typename T>
constexpr bool is_test_v = is_base_test<T>::value;

template<typename T>
class is_derived_from_test : public std::false_type {};

template<typename T>
class is_derived_from_test_helper {
private:
    template<typename X1, typename X2, int A>
    static std::true_type test(const Test1<X1, X2, A>*) {
        return {};
    }
    static std::false_type test(...) { return {}; }

public:
    static constexpr bool value = decltype(test(std::declval<T*>()))::value;
};

template<typename T>
concept is_derived_from_test_c = is_derived_from_test_helper<T>::value;

template<typename T>
requires is_derived_from_test_c<T>
class is_derived_from_test<T> : public std::true_type {};

template<typename T>
constexpr bool is_derived_from_test_v = is_derived_from_test<T>::value;

int main() {
    std::cout << std::boolalpha << is_test_v<Test1<double, char, 3>> << std::endl;
    std::cout << std::boolalpha << is_test_v<Test2> << std::endl;
    std::cout << std::boolalpha << is_test_v<int> << std::endl;
    std::cout << std::boolalpha << is_test_v<void> << std::endl;
    std::cout << std::boolalpha << is_test_v<void*> << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << std::boolalpha << is_derived_from_test_v<Test1<double, char, 3>> << std::endl;
    std::cout << std::boolalpha << is_derived_from_test_v<Test2> << std::endl;
    std::cout << std::boolalpha << is_derived_from_test_v<int> << std::endl;
    std::cout << std::boolalpha << is_derived_from_test_v<void> << std::endl;
    std::cout << std::boolalpha << is_derived_from_test_v<void*> << std::endl;

    // LeetCodeTestCaseReader<std::vector<int>(const std::vector<int>&, int)> leetCodeTestCaseReader{
    //     R"(D:\Work Space\leetcode\cpp\tasks\task_input\test1.txt)"};

    // leetCodeTestCaseReader.forEachTestCase([](const std::vector<int>& vr, const std::vector<int>& v1, int i1) -> void {
    //     for (auto i : vr) std::cout << i << ", ";
    //     std::cout << std::endl;

    //     for (auto i : v1) std::cout << i << ", ";
    //     std::cout << std::endl;

    //     std::cout << i1 << std::endl;
    // });

    return 0;
}
