/**
  ******************************************************************************
  * @file           : task454.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-24
  ******************************************************************************
  */

#ifndef LEETCODE_TASK454_H
#define LEETCODE_TASK454_H

#include "../task.hpp"

class Task454 : public Task<454, int(const std::vector<int> &, const std::vector<int> &, const std::vector<int> &,
                                     const std::vector<int> &)> {
public:
    Task454();

    ~Task454() noexcept override = default;

    [[nodiscard]] std::string title() const override {
        return "四数相加 II";
    }

    [[nodiscard]] int solve(const std::vector<int> &nums1, const std::vector<int> &nums2, const std::vector<int> &nums3,
              const std::vector<int> &nums4) const override;
};

#endif //LEETCODE_TASK454_H
