/**
 ******************************************************************************
 * @file           : task_type_traits.hpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-4-18
 ******************************************************************************
 */

#ifndef LEETCODE_TASK_TYPE_TRAITS_HPP
#define LEETCODE_TASK_TYPE_TRAITS_HPP

#include <map>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace TypeTraits {

    template<typename T>
    class is_vector : public std::false_type {};

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
    concept is_vector_c = is_vector_v<T>;

    template<typename T>
    struct is_set : public std::false_type {};

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
    concept is_set_c = is_set_v<T>;

    template<typename T>
    concept is_container_c = requires(T a) {
        { std::begin(a) } -> std::input_iterator;
        { std::end(a) } -> std::sentinel_for<decltype(std::begin(a))>;
    };

    template<typename T>
    struct is_container : public std::false_type {};

    template<typename T>
    requires is_container_c<T>
    struct is_container<T> : public std::true_type {};

    template<typename T>
    constexpr bool is_container_v = is_container<T>::value;

    template<typename T>
    using clean_type_t = std::conditional_t<
            std::is_same_v<std::remove_cvref_t<T>, std::ostringstream>,
            T,
            std::remove_cvref_t<T>
    >;

}  // namespace TypeTraits

template<typename Func>
class TestCaseReader;

template<typename Res, typename... Args>
class TestCaseReader<Res(Args...)>;

template<typename InputRes, typename OutputRes>
class TestResultProcessor;

namespace TypeTraits {
    template<typename T>
    class is_any_test_case_reader : public std::false_type {};

    template<typename T>
    class _is_any_test_case_reader_helper {
    private:
        template<typename Res, typename... Args>
        static std::true_type _helper(const TestCaseReader<Res(Args...)> *) {
            return {};
        }

        static std::false_type _helper(...) { return {}; }

    public:
        static constexpr bool value = decltype(_helper(std::declval<T *>()))::value;
    };

    template<typename T>
    concept is_any_test_case_reader_c = _is_any_test_case_reader_helper<T>::value;

    template<typename T>
    requires is_any_test_case_reader_c<T>
    class is_any_test_case_reader<T> : public std::true_type {};

    template<typename T>
    class is_test_case_reader : public std::conjunction<is_any_test_case_reader<T>, std::negation<std::is_abstract<T>>> {};

    template<typename T>
    constexpr bool is_test_case_reader_v = is_test_case_reader<T>::value;

    template<typename T>
    concept is_test_case_reader_c = is_test_case_reader_v<T>;

    template<typename T>
    class is_any_test_result_processor : public std::false_type {};

    template<typename T>
    class _is_any_test_result_processor {
    private:
        template<typename InputRes, typename OutputRes>
        static std::true_type _helper(const TestResultProcessor<InputRes, OutputRes> *) {
            return {};
        }

        static std::false_type _helper(...) { return {}; }

    public:
        static constexpr bool value = decltype(_helper(std::declval<T *>()))::value;
    };

    template<typename T>
    concept is_any_test_result_processor_c = _is_any_test_result_processor<T>::value;

    template<typename T>
    requires is_any_test_result_processor_c<T>
    class is_any_test_result_processor<T> : public std::true_type {};

    template<typename T>
    class is_test_result_processor : public std::conjunction<is_any_test_result_processor<T>, std::negation<std::is_abstract<T>>> {};

    template<typename T>
    constexpr bool is_test_result_processor_v = is_test_result_processor<T>::value;

    template<typename T>
    concept is_test_result_processor_c = is_test_result_processor_v<T>;

}  // namespace TypeTraits

template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Func>
class Task;

template<const char *Name, TypeTraits::is_test_case_reader_c Reader, TypeTraits::is_test_result_processor_c Processor, typename Res, typename... Args>
class Task<Name, Reader, Processor, Res(Args...)>;

namespace TypeTraits {
    template<typename T>
    class is_any_task : public std::false_type {};

    template<typename T>
    class _is_any_task_helper {
    private:
        template<const char *Name, typename Reader, typename Processor, typename Res, typename... Args>
        static std::true_type _helper(const Task<Name, Reader, Processor, Res(Args...)> *) {
            return {};
        }

        static std::false_type _helper(...) { return {}; }

    public:
        static constexpr bool value = decltype(_helper(std::declval<T *>()))::value;
    };

    template<typename T>
    concept is_any_task_c = _is_any_task_helper<T>::value;

    template<typename T>
    requires is_any_task_c<T>
    class is_any_task<T> : public std::true_type {};

    template<typename T>
    constexpr bool is_any_task_v = is_any_task<T>::value;

    template<typename T>
    class is_task : public std::conjunction<is_any_task<T>, std::negation<std::is_abstract<T>>> {};

    template<typename T>
    constexpr bool is_task_v = is_task<T>::value;

    template<typename T>
    concept is_task_c = is_task_v<T>;

    template<typename T, typename R, typename P>
    class is_task_fit : public std::false_type {};

    template<is_any_task_c T, is_test_case_reader_c R, is_test_result_processor_c P>
    class _is_task_fit_helper {
    private:
        template<const char *Name, typename Res, typename Any, typename... Args>
        static std::true_type _helper(const Task<Name, R, P, Res(Args...)> *, const TestCaseReader<Res(Args...)> *,
                                      const TestResultProcessor<Res, Any> *) {
            return {};
        }

        static std::false_type _helper(...) { return {}; }

    public:
        static constexpr bool value = decltype(_helper(std::declval<T *>(), std::declval<R *>(), std::declval<P *>()))::value;
    };

    template<typename T, typename R, typename P>
    concept is_task_fit_c = _is_task_fit_helper<T, R, P>::value;

    template<is_any_task_c T, is_test_case_reader_c R, is_test_result_processor_c P>
    requires is_task_fit_c<T, R, P>
    class is_task_fit<T, R, P> : public std::true_type {};

    template<typename T, typename R, typename P>
    constexpr bool is_task_fit_v = is_task_fit<T, R, P>::value;

}  // namespace TypeTraits

#endif  // LEETCODE_TASK_TYPE_TRAITS_HPP
