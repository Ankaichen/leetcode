/**
  ******************************************************************************
  * @file           : parse.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-18
  ******************************************************************************
  */

#ifndef LEETCODE_PARSE_HPP
#define LEETCODE_PARSE_HPP

#include <ranges>
#include <string>
#include <sstream>
#include <type_traits>
#include <vector>
#include <set>
#include <unordered_set>
#include <stack>
#include <cassert>

#include "parameter_type_traits.hpp"

namespace Parse {

    template<typename T>
    static std::remove_cv_t<std::remove_reference_t<T>> parseType(const std::string &input);

    namespace _detail {

        template<unsigned int Index>
        static std::string stringSlice(const std::string &input) {
            int sliceIndex{-1};
            unsigned int i{0}, startIndex1{0};
            for (; i < input.size(); ++i) {
                if (input[i] == ';') {
                    ++sliceIndex;
                    if (sliceIndex == Index) {
                        break;
                    } else {
                        startIndex1 = i + 1;
                    }
                } else if (input[i] == '=') {
                    startIndex1 = i + 1;
                }
            }
            return input.substr(startIndex1, i - startIndex1);
        }

        template<typename T>
        static T parseValue(const std::string &input) {
            if constexpr (std::is_same_v<T, char>) {
                return input[0];
            } else if constexpr (std::is_same_v<T, unsigned char>) {
                return static_cast<unsigned char>(std::stoi(input));
            } else if constexpr (std::is_same_v<T, int>) {
                return std::stoi(input);
            } else if constexpr (std::is_same_v<T, long>) {
                return std::stol(input);
            } else if constexpr (std::is_same_v<T, long long>) {
                return std::stoll(input);
            } else if constexpr (std::is_same_v<T, unsigned int>) {
                return static_cast<T>(std::stoul(input));
            } else if constexpr (std::is_same_v<T, unsigned long>) {
                return std::stoul(input);
            } else if constexpr (std::is_same_v<T, unsigned long long>) {
                return std::stoull(input);
            } else if constexpr (std::is_same_v<T, float>) {
                return std::stof(input);
            } else if constexpr (std::is_same_v<T, double>) {
                return std::stod(input);
            } else if constexpr (std::is_same_v<T, bool>) {
                if (input == "true") return true;
                else return false;
            } else {
                static_assert(false);
            }
        }

        template<typename T>
        static std::vector<TypeTraits::vector_value_t<T>> parseVector(const std::string &input) {
            using result_type = TypeTraits::vector_value_t<T>;
            std::vector<result_type> result;
            unsigned int firstIndex = input.find('[') + 1;
            unsigned int lastIndex = input.find_last_of(']');
            std::stringstream ss{""};
            std::stack<char> charStack{};
            for (unsigned int i = firstIndex; i < lastIndex; ++i) {
                char c = input[i];
                if (c == '[') {
                    charStack.push(c);
                    ss << c;
                } else if (c == ']') {
                    assert(charStack.top() == '[');
                    ss << c;
                    charStack.pop();
                } else if (c == ',') {
                    if (charStack.empty()) {
                        std::string curValue{ss.str()};
                        if (!curValue.empty()) {
                            result.push_back(parseType<result_type>(curValue));
                        }
                        { decltype(ss) temp = std::move(ss); }
                    } else {
                        ss << c;
                    }
                } else {
                    ss << c;
                }
            }
            std::string lastValue{ss.str()};
            if (!lastValue.empty()) {
                result.push_back(parseType<result_type>(lastValue));
            }
            return result;
        }

        static ListNode *parseListNode(const std::string &input) {
            using ValType = decltype(std::declval<ListNode>().val);
            std::vector<ValType> vec = parseVector<std::vector<ValType>>(input);
            ListNode *p = nullptr, *q = nullptr;
            for (int i: std::ranges::reverse_view(vec)) {
                q = new ListNode(i, p);
                p = q;
            }
            return p;
        }


        template<typename T>
        static T parseSet(const std::string &input) {
            using result_type = TypeTraits::set_value_t<T>;
            T result;
            unsigned int firstIndex = input.find('{') + 1;
            unsigned int lastIndex = input.find_last_of('}');
            std::stringstream ss{""};
            std::stack<char> charStack{};
            for (unsigned int i = firstIndex; i < lastIndex; ++i) {
                char c = input[i];
                if (c == '[' || c == '{') {
                    charStack.push(c);
                    ss << c;
                } else if (c == ']' || c == '}') {
                    assert(charStack.top() == '[' || charStack.top() == '{');
                    ss << c;
                    charStack.pop();
                } else if (c == ',') {
                    if (charStack.empty()) {
                        std::string curValue{ss.str()};
                        if (!curValue.empty()) {
                            result.insert(parseType<result_type>(curValue));
                        }
                        { decltype(ss) temp = std::move(ss); }
                    } else {
                        ss << c;
                    }
                } else {
                    ss << c;
                }
            }
            std::string lastValue{ss.str()};
            if (!lastValue.empty()) {
                result.insert(parseType<result_type>(lastValue));
            }
            return result;
        }

        static std::string parseString(const std::string &input) {
            unsigned int firstIndex = input.find('"') + 1;
            unsigned int lastIndex = input.find_last_of('"');
            return input.substr(firstIndex, lastIndex - firstIndex);
        }

        template<typename T>
        static std::remove_cv_t<std::remove_reference_t<T>> parseContainer(const std::string &input) {
            using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
            if constexpr (std::is_same_v<ParseType, std::string>) {
                return parseString(input);
            } else if constexpr (TypeTraits::is_vector_v<ParseType>) {
                return parseVector<ParseType>(input);
            } else if constexpr (TypeTraits::is_set_v<ParseType>) {
                return parseSet<ParseType>(input);
            }
        }

    }

    /**
     * Parsing a string with a single parameter
     * @tparam T    parameter type
     * @param input input parameter string
     * @return      parameter value
     */
    template<typename T>
    static std::remove_cv_t<std::remove_reference_t<T>> parseType(const std::string &input) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        if constexpr (std::is_arithmetic_v<ParseType>) {
            return _detail::parseValue<ParseType>(input);
        } else if constexpr (TypeTraits::is_container_v<ParseType>) {
            return _detail::parseContainer<ParseType>(input);
        } else if constexpr (std::is_same_v<ParseType, ListNode *>) {
            return _detail::parseListNode(input);
        }
    }

    /**
     * Parsing a parameter of string by index
     * @tparam Index parameter index
     * @tparam T     parameter type
     * @param input  input parameter string
     * @return       parameter value
     */
    template<unsigned int Index, typename T>
    static std::remove_cv_t<std::remove_reference_t<T>> parseTypeByIndex(const std::string &input) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        std::string slicedString = _detail::stringSlice<Index>(input);
        return parseType<ParseType>(slicedString);
    }

    template<typename T>
    static std::string toString(const T &value) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        if constexpr (std::is_same_v<ParseType, char>) {
            return std::string{static_cast<char>(value)};
        } else if constexpr (std::is_same_v<ParseType, bool>) {
            std::stringstream ss;
            ss << std::boolalpha << value;
            return ss.str();
        } else if constexpr (std::is_arithmetic_v<ParseType>) {
            return std::to_string(value);
        } else if constexpr (TypeTraits::is_container_v<ParseType>) {
            if constexpr (std::is_same_v<ParseType, std::string>) {
                return "\"" + value + "\"";
            }
            std::string rng1 = "[", rng2 = "]";
            if constexpr (TypeTraits::is_set_v<ParseType>) {
                rng1 = "{";
                rng2 = "}";
            }
            std::stringstream ss;
            ss << rng1;
            auto i = value.cbegin();
            if (i != value.cend()) {
                ss << toString(*i);
                for (++i; i != value.cend(); ++i) {
                    ss << "," << toString(*i);
                }
            }
            ss << rng2;
            return ss.str();
        } else if constexpr (std::is_same_v<ParseType, ListNode *>) {
            using ValType = decltype(std::declval<ListNode>().val);
            ListNode *p = value;
            std::vector<ValType> vec;
            while (p != nullptr) {
                vec.push_back(p->val);
                p = p->next;
            }
            return toString(vec);
        }
    }

};

#endif //LEETCODE_PARSE_HPP
