/**
  ******************************************************************************
  * @file           : task509.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-5-8
  ******************************************************************************
  */

#ifndef LEETCODE_TASK509_HPP
#define LEETCODE_TASK509_HPP

#include "../task.hpp"

class Task509 : public Task<509, int(int)> {
public:
    Task509();
    ~Task509() noexcept override = default;
    [[nodiscard]] std::string title() const override {
        return "斐波那契数";
    }
    [[nodiscard]] int solve(int n) const override;
};

Task509::Task509() {
    this->addTestCase("n = 39", "63245986");
    this->addTestCase("n = 23", "28657");
    this->addTestCase("n = 33", "3524578");
}

int fib1(int n) {
    static std::vector<int> fibVec{0, 1};
    if (fibVec.size() <= n) {
        for (int i = fibVec.size(); i <= n; ++i) {
            fibVec.push_back(fibVec[i - 1] + fibVec[i - 2]);
        }
    }
    return fibVec[n];
}

int fib2(int n) {
    if (n == 0) return 0;
    int dp_1 = 0, dp_2 = 1;
    for (int i = 2; i <= n; ++i) {
        int sum = dp_1 + dp_2;
        dp_1 = dp_2;
        dp_2 = sum;
    }
    return dp_2;
}

int Task509::solve(int n) const {
    return fib2(n);
}

#endif //LEETCODE_TASK509_HPP
