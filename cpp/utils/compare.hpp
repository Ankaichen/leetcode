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

#include <vector>
#include <type_traits>
#include <cmath>
#include <iterator>
#include <algorithm>

#include "parameter_type_traits.hpp"

namespace Compare {

    namespace _detail {

        template<typename T>
        bool compareIntegral(T value1, T value2) {
            static_assert(std::is_integral_v<T>);
            return value1 == value2;
        }

        template<typename T>
        bool compareFloatingPoint(T value1, T value2, T epsilon = 1e-6) {
            static_assert(std::is_floating_point_v<T>);
            return std::fabs(value1 - value2) < epsilon;
        }

        template<typename T>
        bool compareContainer(const T &value1, const T &value2) {
            static_assert(TypeTraits::is_container_v<T>);
            return std::equal(value1.cbegin(), value1.cend(), value2.cbegin(), value2.cend());
        }
    }

    template<typename T>
    bool compare(const T &value1, const T &value2) {
        if constexpr (std::is_integral_v<T>) {
            return _detail::compareIntegral(value1, value2);
        } else if constexpr (std::is_floating_point_v<T>) {
            return _detail::compareFloatingPoint(value1, value2);
        } else if constexpr (TypeTraits::is_container_v<T>) {
            return _detail::compareContainer(value1, value2);
        }
    }

}

#endif //LEETCODE_COMPARE_HPP
