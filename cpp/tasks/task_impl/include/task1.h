/**
 ******************************************************************************
 * @file           : task1.h
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-4-18
 ******************************************************************************
 */

#ifndef LEETCODE_TASK1_H
#define LEETCODE_TASK1_H

#define 

#define DEFINE_TASK(TASK_NAME, NAME, READER, PROCESSOR, RES, ARGS) \
                                                                   \
    static constexpr char Name[] = NAME;                           \
    class TASK_NAME : public Task<Name, >

#undef DEFINE_TASK

#include "../../core/task.hpp"
#include "../../core/test_case_reader.hpp"
#include "../../core/test_result_processor.hpp"

static constexpr char Name[] = "1.两数之和";

class LeetcodeTask1 : public Task<Name, LeetCodeTestCaseReader<std::vector<int>(const std::vector<int> &, int)>,
                                  NormalTestResultProcessor<std::vector<int>>, std::vector<int>(const std::vector<int> &, int)> {
public:
    LeetcodeTask1() = default;
    ~LeetcodeTask1() noexcept override = default;
    INIT_TESTCASE_FILE_NAME
    [[nodiscard]] std::vector<int> solve(const std::vector<int> &nums, int target) const override;
};

#endif  // LEETCODE_TASK1_H
