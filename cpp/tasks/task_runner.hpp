/**
  ******************************************************************************
  * @file           : task_runner.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-19
  ******************************************************************************
  */

#ifndef LEETCODE_TASK_RUNNER_HPP
#define LEETCODE_TASK_RUNNER_HPP

#include <iostream>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>
#include <cassert>
#include <iomanip>

#include "task.hpp"
#include "../color_out/color_out.h"
#include "../utils/parameter_type_traits.hpp"

/**
 * Used to run tasks and output results
 * @tparam T task class
 */
template<typename T>
class TaskRunner {
    static_assert(TypeTraits::is_task_v<T>);
private:
    struct TableItem {
        ColorOut::TextStyle color;
        std::string value;
    };
public:
    ~TaskRunner() noexcept = default;

    TaskRunner(const TaskRunner &) = delete;

    TaskRunner(TaskRunner &&) = delete;

    static inline const TaskRunner &getInstance();

    inline void run() const;

private:
    TaskRunner() {
#ifdef PLATFORM_WINDOWS
        system("chcp 65001 > nul");
#endif
    };

    inline std::vector<std::vector<TableItem>> createTableData(const std::vector<TestResult> &runResult) const;

    static inline std::vector<std::size_t>
    calculateColumnWidth(const std::vector<std::vector<TableItem>> &table, size_t padding = 1);

    static inline void printLine(const std::vector<size_t> &widths, std::string_view corner_left,
                                 std::string_view corner_mid, std::string_view corner_right, std::string_view horiz,
                                 const ColorOut::TextStyle &textStyle = ColorOut::default_fg);

    static inline void printTable(const std::vector<std::vector<TableItem>> &table,
                                  const ColorOut::TextStyle &lineColor = ColorOut::default_fg);

private:
    T task;
};

template<typename T>
const TaskRunner<T> &TaskRunner<T>::getInstance() {
    static const TaskRunner<T> tr{};
    return tr;
}

template<typename T>
void TaskRunner<T>::run() const {
    std::cout << this->task.id << ". " << this->task.title() << std::endl;
    std::vector<TestResult> result = this->task.test();
    std::vector<std::vector<TableItem>> table = this->createTableData(result);
    printTable(table, ColorOut::white_fg);
}

template<typename T>
std::vector<std::vector<typename TaskRunner<T>::TableItem>>
TaskRunner<T>::createTableData(const std::vector<TestResult> &runResult) const {
    const std::vector<TestCase> &testCase = this->task.getTestCase();
    assert(testCase.size() == runResult.size());
    std::vector<std::vector<TableItem>> table;
    std::vector<TableItem> column;
    // id
    column.emplace_back(ColorOut::default_fg, "Id");
    for (unsigned int i = 0; i < runResult.size(); ++i) {
        const auto &c = runResult[i].flag ? ColorOut::green_fg : ColorOut::red_fg;
        column.emplace_back(c, std::to_string(i + 1));
    }
    table.emplace_back(std::move(column));
    // test case input
    column.emplace_back(ColorOut::default_fg, "Input");
    for (unsigned int i = 0; i < runResult.size(); ++i) {
        const auto &c = runResult[i].flag ? ColorOut::green_fg : ColorOut::red_fg;
        column.emplace_back(c, testCase[i].input);
    }
    table.emplace_back(std::move(column));
    // test case expected
    column.emplace_back(ColorOut::default_fg, "Expected Output");
    for (unsigned int i = 0; i < runResult.size(); ++i) {
        const auto &c = runResult[i].flag ? ColorOut::green_fg : ColorOut::red_fg;
        column.emplace_back(c, testCase[i].expected);
    }
    table.emplace_back(std::move(column));
    // test case actual output
    column.emplace_back(ColorOut::default_fg, "Actual Output");
    for (const auto & i : runResult) {
        const auto &c = i.flag ? ColorOut::green_fg : ColorOut::red_fg;
        column.emplace_back(c, i.output);
    }
    table.emplace_back(std::move(column));
    // status
    column.emplace_back(ColorOut::default_fg, "Status");
    for (const auto &i: runResult) {
        const auto &c = i.flag ? ColorOut::green_fg : ColorOut::red_fg;
        column.emplace_back(c, i.flag ? "Pass" : "Failed");
    }
    table.emplace_back(std::move(column));
    return table;
}

template<typename T>
std::vector<std::size_t>
TaskRunner<T>::calculateColumnWidth(const std::vector<std::vector<TableItem>> &table, size_t padding) {
    size_t colCount = table.size();
    std::vector<size_t> widths(colCount, 0);
    for (unsigned int i = 0; i < colCount; ++i) {
        for (auto &item: table[i]) {
            widths[i] = std::max(widths[i], item.value.size());
        }
    }
    for (auto &w: widths) w += padding * 2;  // 左右各留 padding 空格
    return widths;
}

template<typename T>
void
TaskRunner<T>::printLine(const std::vector<size_t> &widths, std::string_view corner_left, std::string_view corner_mid,
                         std::string_view corner_right, std::string_view horiz, const ColorOut::TextStyle &textStyle) {
    std::cout << textStyle << corner_left;
    for (std::size_t i = 0; i < widths.size(); ++i) {
        for (std::size_t j = 0; j < widths[i]; ++j) std::cout << horiz;
        if (i + 1 < widths.size()) std::cout << corner_mid;
    }
    std::cout << corner_right << ColorOut::reset << "\n";
}

template<typename T>
void TaskRunner<T>::printTable(const std::vector<std::vector<TableItem>> &table, const ColorOut::TextStyle &lineColor) {
    std::vector<std::size_t> widths = calculateColumnWidth(table);
    unsigned int colCount = table.size();
    unsigned int rowCount = table[0].size();
    // top line
    printLine(widths, "┌", "┬", "┐", "─", lineColor);
    for (unsigned int i = 0; i < rowCount; ++i) {
        std::cout << lineColor << "│" << ColorOut::reset;
        for (unsigned int j = 0; j < colCount; ++j) {
            size_t w = widths[j];
            const TableItem &item = table[j][i];
            std::cout << item.color << ' ' << std::right << std::setw(static_cast<int>(w - 2)) << item.value << ColorOut::reset << ' '
                      << lineColor << "│" << ColorOut::reset;
        }
        std::cout << "\n";
    }
    // bottom line
    printLine(widths, "└", "┴", "┘", "─", lineColor);
}

#endif //LEETCODE_TASK_RUNNER_HPP
