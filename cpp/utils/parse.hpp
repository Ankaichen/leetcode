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

#include <string>
#include <sstream>
#include <type_traits>
#include <vector>

#include "parameter_type_traits.hpp"

namespace Parse {

    namespace _detail {

        template<unsigned int Index>
        std::string stringSlice(const std::string &input) {
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
        T parseValue(const std::string &input) {
            // TODO parse char
            if constexpr (std::is_same_v<T, int>) {
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
            } else {
                static_assert(false);
            }
        }

        template<typename T>
        std::vector<TypeTraits::is_vector_value_type<T>> parseVector(const std::string &input) {
            using result_type = TypeTraits::is_vector_value_type<T>;
            std::vector<result_type> result;
            unsigned int firstIndex = input.find('[') + 1;
            unsigned int lastIndex = input.find_last_of(']');
            std::stringstream ss{""};
            for (unsigned int i = firstIndex; i < lastIndex; ++i) {
                char c = input[i];
                if (c == ',') {
                    std::string curValue{ss.str()};
                    if (!curValue.empty()) {
                        result.push_back(parseValue<result_type>(curValue));
                    }
                    { decltype(ss) temp = std::move(ss); }
                } else {
                    ss << c;
                }
            }
            std::string lastValue{ss.str()};
            if (!lastValue.empty()) {
                result.push_back(parseValue<result_type>(lastValue));
            }
            return result;
        }

    }

    /**
     * Parsing a string with a single parameter
     * @tparam T    parameter type
     * @param input input parameter string
     * @return      parameter value
     */
    template<typename T>
    std::remove_cv_t<std::remove_reference_t<T>> parseType(const std::string &input) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        if constexpr (TypeTraits::is_value_v<ParseType>) {
            return _detail::parseValue<ParseType>(input);
        } else if constexpr (TypeTraits::is_removed_vector_v<ParseType>) {
            return _detail::parseVector<ParseType>(input);
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
    std::remove_cv_t<std::remove_reference_t<T>> parseTypeByIndex(const std::string &input) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        std::string slicedString = _detail::stringSlice<Index>(input);
        return parseType<ParseType>(slicedString);
    }

    template<typename T>
    std::string toString(const T &value) {
        using ParseType = std::remove_cv_t<std::remove_reference_t<T>>;
        if constexpr (std::is_same_v<ParseType, char>) {
            return std::string{static_cast<char>(value)};
        } else if constexpr (std::is_arithmetic_v<ParseType>) {
            return std::to_string(value);
        } else if constexpr (TypeTraits::is_container_v<ParseType>) {
            std::stringstream ss;
            ss << "[";
            auto i = value.cbegin();
            if (i != value.cend()) {
                ss << (*i);
                for (++i; i != value.cend(); ++i) {
                    ss << "," << toString(*i);
                }
            }
            ss << "]";
            return ss.str();
        } else {
            return "";
        }
    }

};

#endif //LEETCODE_PARSE_HPP
