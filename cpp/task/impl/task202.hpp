/**
  ******************************************************************************
  * @file           : task202.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK202_HPP
#define LEETCODE_TASK202_HPP

#include "../task.hpp"

class Task202 : public Task<202, bool(int)> {
public:
    Task202();

    ~Task202() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "快乐数";
    }

    [[nodiscard]] bool solve(int n) const override;
};

Task202::Task202() {
    this->addTestCase("n = 19", "true");
    this->addTestCase("n = 2", "false");
}

#include <unordered_set>

bool isHappy(int n) {
    std::unordered_set<int> set{n};
    while (true) {
        int sum = 0;
        for (int temp_n = n; temp_n != 0; temp_n /= 10) {
            int single_n = temp_n % 10;
            sum += (single_n * single_n);
        }
        if (sum == 1) {
            return true;
        } else if (set.find(sum) != set.end()) {
            return false;
        } else {
            set.insert(sum);
            n = sum;
        }
    }
}

bool Task202::solve(int n) const {
    return isHappy(n);
}

#endif //LEETCODE_TASK202_HPP
