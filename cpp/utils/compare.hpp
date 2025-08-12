/**
 ******************************************************************************
 * @file           : compare.hpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-4-18
 ******************************************************************************
 */

#ifndef LEETCODE_COMPARE_HPP
#define LEETCODE_COMPARE_HPP

#include <algorithm>
#include <cmath>
#include <iterator>
#include <sstream>
#include <type_traits>
#include <vector>

#include "../tasks/core/task_type_traits.hpp"
#include "../tasks/core/utils.h"

namespace Compare {

    namespace _detail {

        template<typename T>
        static bool compareIntegral(T value1, T value2) {
            static_assert(std::is_integral_v<T>);
            return value1 == value2;
        }

        template<typename T>
        static bool compareFloatingPoint(T value1, T value2, T epsilon = 1e-6) {
            static_assert(std::is_floating_point_v<T>);
            return std::fabs(value1 - value2) < epsilon;
        }

        template<typename T>
        static bool compareContainer(const T &value1, const T &value2) {
            static_assert(TypeTraits::is_container_v<T>);
            return std::equal(value1.cbegin(), value1.cend(), value2.cbegin(), value2.cend());
        }

        static bool compareListNode(ListNode *value1, ListNode *value2) {
            using ValType = decltype(std::declval<ListNode>().val);
            while (value1 != nullptr && value2 != nullptr) {
                if (value1->val != value2->val) return false;
                value1 = value1->next;
                value2 = value2->next;
            }
            return (value1 == nullptr) && (value2 == nullptr);
        }

        static bool compareStringStream(std::ostringstream &value1, std::ostringstream &value2) {
            std::string line1{}, line2{};
            std::istringstream value1_i{value1.str()}, value2_i{value2.str()};
            while (std::getline(value1_i, line1) && std::getline(value2_i, line2)) {
                if (line1 != line2) return false;
            }
            while (std::getline(value1_i, line1)) {
                if (line1 != "") return false;
            }
            while (std::getline(value2_i, line2)) {
                if (line2 != "") return false;
            }
            return true;
        }
    }  // namespace _detail

    template<typename T>
    static bool compare(const T &value1, const T &value2) {
        using CompareType = std::remove_cvref_t<T>;
        if constexpr (std::is_integral_v<CompareType>) {
            return _detail::compareIntegral(value1, value2);
        } else if constexpr (std::is_floating_point_v<CompareType>) {
            return _detail::compareFloatingPoint(value1, value2);
        } else if constexpr (TypeTraits::is_container_v<CompareType>) {
            return _detail::compareContainer(value1, value2);
        } else if constexpr (std::is_same_v<CompareType, ListNode *>) {
            return _detail::compareListNode(value1, value2);
        } else if constexpr (std::is_same_v<CompareType, std::ostringstream>) {
            return _detail::compareStringStream(const_cast<std::ostringstream &>(value1), const_cast<std::ostringstream &>(value2));
        }
    }

}  // namespace Compare

#endif  // LEETCODE_COMPARE_HPP
