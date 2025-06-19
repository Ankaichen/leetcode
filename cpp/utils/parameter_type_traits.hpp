/**
  ******************************************************************************
  * @file           : parameter_type_traits.hpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-18
  ******************************************************************************
  */

#ifndef LEETCODE_PARAMETER_TYPE_TRAITS_HPP
#define LEETCODE_PARAMETER_TYPE_TRAITS_HPP

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <type_traits>

#include "../tasks/forward_declaration.h"

namespace TypeTraits {

    template<typename T>
    class is_vector : public std::false_type {
    };

    template<typename T>
    class is_vector<std::vector<T>> : public std::true_type {
    public:
        using value_type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    constexpr bool is_vector_v = is_vector<T>::value;

    template<typename T>
    using vector_value_t = is_vector<T>::value_type;

    template<typename T>
    struct is_set : public std::false_type {
    };

    template<typename T>
    struct is_set<std::set<T>> : public std::true_type {
    public:
        using value_type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    struct is_set<std::unordered_set<T>> : public std::true_type {
    public:
        using value_type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    struct is_set<std::multiset<T>> : public std::true_type {
    public:
        using value_type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    struct is_set<std::unordered_multiset<T>> : public std::true_type {
    public:
        using value_type = std::remove_cv_t<std::remove_reference_t<T>>;
    };

    template<typename T>
    constexpr bool is_set_v = is_set<T>::value;

    template<typename T>
    using set_value_t = is_set<T>::value_type;

    template<typename T, typename = void>
    struct is_container : std::false_type {
    };

    template<typename T>
    struct is_container<T, std::void_t<decltype(std::begin(std::declval<T>())),
            decltype(std::end(std::declval<T>()))>> : std::true_type {
    };

    template<typename T>
    inline constexpr bool is_container_v = is_container<T>::value;

    template<typename T>
    struct is_base_task : std::false_type {
    };

    template<unsigned int ID, typename Res, typename... Args>
    struct is_base_task<Task<ID, Res(Args...)>> : std::true_type {
    };

    template<typename T>
    inline constexpr bool is_base_task_v = is_base_task<T>::value;

    template<typename T>
    struct is_task : public std::conjunction<is_base_task<typename T::BaseType>, std::negation<std::is_abstract<T>>> {
    };

    template<typename T>
    inline constexpr bool is_task_v = is_task<T>::value;
}

#endif //LEETCODE_PARAMETER_TYPE_TRAITS_HPP
