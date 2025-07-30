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

#include "../tasks/core/forward_declaration.h"

namespace TypeTraits {

    template<typename T>
    class is_vector : public std::false_type {
    };

    template<typename T>
    class is_vector<std::vector<T>> : public std::true_type {
    public:
        using value_type = std::remove_cvref_t<T>;
    };

    template<typename T>
    constexpr bool is_vector_v = is_vector<T>::value;

    template<typename T>
    using vector_value_t = is_vector<T>::value_type;

    template<typename T>
    concept vector_c = is_vector_v<T>;

    template<typename T>
    struct is_set : public std::false_type {
    };

    template<typename T>
    struct is_set<std::set<T>> : public std::true_type {
    public:
        using value_type = std::remove_cvref_t<T>;
    };

    template<typename T>
    struct is_set<std::unordered_set<T>> : public std::true_type {
    public:
        using value_type = std::remove_cvref_t<T>;
    };

    template<typename T>
    struct is_set<std::multiset<T>> : public std::true_type {
    public:
        using value_type = std::remove_cvref_t<T>;
    };

    template<typename T>
    struct is_set<std::unordered_multiset<T>> : public std::true_type {
    public:
        using value_type = std::remove_cvref_t<T>;
    };

    template<typename T>
    constexpr bool is_set_v = is_set<T>::value;

    template<typename T>
    using set_value_t = is_set<T>::value_type;

    template<typename T>
    concept set_c = is_set_v<T>;

    template<typename T>
    concept container_c = requires(T a) {
        { std::begin(a) } -> std::input_iterator;
        { std::end(a) } -> std::sentinel_for<decltype(std::begin(a))>;
    };

    template<typename T>
    struct is_container : std::false_type {
    };

    template<typename T>
    requires container_c<T>
    struct is_container<T> : std::true_type {
    };

    template<typename T>
    constexpr bool is_container_v = is_container<T>::value;

    template<typename T>
    struct is_base_task : std::false_type {
    };

    template<const char *Name, typename Res, typename... Args>
    struct is_base_task<Task<Name, Res(Args...)>> : std::true_type {
    };

    template<typename T>
    constexpr bool is_base_task_v = is_base_task<T>::value;

    template<typename T>
    struct is_task : public std::conjunction<is_base_task<typename T::BaseType>, std::negation<std::is_abstract<T>>> {
    };

    template<typename T>
    inline constexpr bool is_task_v = is_task<T>::value;
}

#endif //LEETCODE_PARAMETER_TYPE_TRAITS_HPP
