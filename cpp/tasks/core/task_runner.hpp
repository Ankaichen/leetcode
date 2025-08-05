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

#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "../../color_out/color_out.h"
#include "./task.hpp"
#include "./task_type_traits.hpp"
#include "./test_case_reader.hpp"

/**
 * Used to run tasks and output results
 * @tparam T task class
 */
template<TypeTraits::is_task_c T>
class TaskRunner {
    using Reader = decltype(std::declval<T>()._testCaseReader);

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

    [[nodiscard]] inline std::vector<std::vector<TableItem>> createTableData(const std::vector<TestResult> &runResult) const;

    static inline std::vector<std::size_t> calculateColumnWidth(const std::vector<std::vector<TableItem>> &table, size_t padding = 1);

    static inline void printLine(const std::vector<size_t> &widths, std::string_view corner_left, std::string_view corner_mid,
                                 std::string_view corner_right, std::string_view horiz, const ColorOut::TextStyle &textStyle = ColorOut::default_fg);

    static inline std::vector<std::vector<TableItem>> processMultiLine(const std::vector<std::vector<TableItem>> &table);

    static inline void printTable(const std::vector<std::vector<TableItem>> &table, const ColorOut::TextStyle &lineColor = ColorOut::default_fg);

private:
    T _task;
    mutable Reader _testCaseReader;
};

template<TypeTraits::is_task_c T>
const TaskRunner<T> &TaskRunner<T>::getInstance() {
    static const TaskRunner<T> tr{};
    return tr;
}

template<TypeTraits::is_task_c T>
void TaskRunner<T>::run() const {
    std::cout << this->_task.title() << std::endl;
    std::vector<TestResult> result = this->_task.test();
    std::vector<std::vector<TableItem>> table = this->processMultiLine(this->createTableData(result));
    printTable(table, ColorOut::white_fg);
}

template<TypeTraits::is_task_c T>
std::vector<std::vector<typename TaskRunner<T>::TableItem>> TaskRunner<T>::createTableData(const std::vector<TestResult> &runResult) const {
    this->_testCaseReader.setFile(this->_task.getTestCaseFilePath());
    std::vector<std::vector<TableItem>> table;
    std::vector<TableItem> idColumn, inputColumn, expectedOutputColumn, actualOutputColumn, spendTimeColumn, statusColumn;
    idColumn.emplace_back(ColorOut::default_fg, "Id");
    inputColumn.emplace_back(ColorOut::default_fg, "Input");
    expectedOutputColumn.emplace_back(ColorOut::default_fg, "Expected Output");
    actualOutputColumn.emplace_back(ColorOut::default_fg, "Actual Output");
    spendTimeColumn.emplace_back(ColorOut::default_fg, "Spend Time");
    statusColumn.emplace_back(ColorOut::default_fg, "Status");
    int index = 0;
    this->_testCaseReader.forEachTestCase(nullptr, [&idColumn, &inputColumn, &expectedOutputColumn, &actualOutputColumn, &spendTimeColumn,
                                                    &statusColumn, &runResult, &index](const std::string &input, const std::string &output) {
        assert(index < runResult.size());
        const auto &c = runResult[index].flag ? ColorOut::green_fg : ColorOut::red_fg;
        // id
        idColumn.emplace_back(c, std::to_string(index + 1));
        // test case input
        inputColumn.emplace_back(c, input);
        // test case expected
        expectedOutputColumn.emplace_back(c, output);
        // test case actual output
        actualOutputColumn.emplace_back(c, runResult[index].output);
        // spend time
        std::ostringstream oss;
        oss << std::setprecision(4) << static_cast<double>(runResult[index].spendTime.count()) * 1e-6 << " ms";
        spendTimeColumn.emplace_back(c, oss.str());
        // status
        statusColumn.emplace_back(c, runResult[index].flag ? "Pass" : "Failed");
        ++index;
    });
    table.emplace_back(std::move(idColumn));
    table.emplace_back(std::move(inputColumn));
    table.emplace_back(std::move(expectedOutputColumn));
    table.emplace_back(std::move(actualOutputColumn));
    table.emplace_back(std::move(spendTimeColumn));
    table.emplace_back(std::move(statusColumn));
    return table;
}

template<TypeTraits::is_task_c T>
std::vector<std::size_t> TaskRunner<T>::calculateColumnWidth(const std::vector<std::vector<TableItem>> &table, size_t padding) {
    size_t colCount = table.size();
    std::vector<size_t> widths(colCount, 0);
    for (unsigned int i = 0; i < colCount; ++i) {
        for (auto &item : table[i]) {
            widths[i] = std::max(widths[i], item.value.size());
        }
    }
    for (auto &w : widths) w += padding * 2;  // 左右各留 padding 空格
    return widths;
}

template<TypeTraits::is_task_c T>
void TaskRunner<T>::printLine(const std::vector<size_t> &widths, std::string_view corner_left, std::string_view corner_mid,
                              std::string_view corner_right, std::string_view horiz, const ColorOut::TextStyle &textStyle) {
    std::cout << textStyle << corner_left;
    for (std::size_t i = 0; i < widths.size(); ++i) {
        for (std::size_t j = 0; j < widths[i]; ++j) std::cout << horiz;
        if (i + 1 < widths.size()) std::cout << corner_mid;
    }
    std::cout << corner_right << ColorOut::reset << "\n";
}

template<TypeTraits::is_task_c T>
std::vector<std::vector<typename TaskRunner<T>::TableItem>> TaskRunner<T>::processMultiLine(const std::vector<std::vector<TableItem>> &table) {
    unsigned int colCount = table.size();
    unsigned int rowCount = table[0].size();
    std::vector<std::vector<TableItem>> resTable{colCount, std::vector<TableItem>{}};
    for (unsigned int i = 0; i < rowCount; ++i) {
        int maxLineCount = 0;
        for (unsigned int j = 0; j < colCount; ++j) {
            maxLineCount = std::max(static_cast<int>(std::count(table[j][i].value.begin(), table[j][i].value.end(), '\n')) + 1, maxLineCount);
        }
        for (unsigned int j = 0; j < colCount; ++j) {
            std::vector<TableItem> newCol{};
            std::istringstream iss{table[j][i].value};
            std::string temp{};
            for (int k = 0; k < maxLineCount; ++k) {
                std::getline(iss, temp, '\n');
                newCol.emplace_back(table[j][i].color, temp);
                temp.clear();
            }
            resTable[j].insert(resTable[j].end(), std::make_move_iterator(newCol.begin()), std::make_move_iterator(newCol.end()));
        }
    }
    return resTable;
}

template<TypeTraits::is_task_c T>
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
            std::cout << item.color << ' ' << (j >= 1 && j <= 3 ? std::left : std::right) << std::setw(static_cast<int>(w - 2)) << item.value
                      << ColorOut::reset << ' ' << lineColor << "│" << ColorOut::reset;
        }
        std::cout << "\n";
    }
    // bottom line
    printLine(widths, "└", "┴", "┘", "─", lineColor);
}

#endif  // LEETCODE_TASK_RUNNER_HPP
