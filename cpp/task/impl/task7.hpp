/**
  ******************************************************************************
  * @file           : task7.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-29
  ******************************************************************************
  */

#ifndef LEETCODE_TASK7_HPP
#define LEETCODE_TASK7_HPP

#include "../task.hpp"

class Task7 : public Task<7, int(int)> {
public:
    Task7();
    ~Task7() noexcept override = default;
    std::string title() const override {
        return "整数反转";
    }
    int solve(int x) const override;
};

Task7::Task7() {
    this->addTestCase("x = 123", "321");
    this->addTestCase("x = -123", "-321");
    this->addTestCase("x = 120", "21");
    this->addTestCase("x = 0", "0");
}

int reverse1(int x) {
    if (x <= INT_MIN) return 0;
    int res = 0;
    bool flag = x < 0;
    x = std::abs(x);
    while (x > 0) {
        if (res != 0 && 0x7fffffff / res < 10) {
            return 0;
        } else {
            res *= 10;
        }
        int i = x % 10;
        if ((0x7fffffff - res) < i) {
            return 0;
        } else {
            res += i;
        }
        x = x / 10;
    }
    return flag ? -res : res;
}

int reverse2(int x) {
    int res = 0;
    while (x != 0) {
        if (res < INT_MIN / 10 || res > INT_MAX / 10) {
            return 0;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int Task7::solve(int x) const {
    return reverse2(x);
}

#endif //LEETCODE_TASK7_HPP
