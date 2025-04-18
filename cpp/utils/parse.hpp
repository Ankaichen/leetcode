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

namespace Parse {

    namespace _detail {

        template<typename T>
        class is_value : public std::is_arithmetic<T> {
        };

        template<typename T>
        constexpr bool is_value_v = is_value<T>::value;

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
        class is_clean_vector : public is_vector<std::remove_cv_t<std::remove_reference_t<T>>> {

        };

        template<typename T>
        constexpr bool is_clean_vector_v = is_clean_vector<T>::value;

        template<typename T>
        using is_vector_value_type = is_vector<T>::value_type;

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
        std::vector<is_vector_value_type<T>> parseVector(const std::string &input) {
            using result_type = is_vector_value_type<T>;
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
        if constexpr (_detail::is_value_v<ParseType>) {
            return _detail::parseValue<ParseType>(input);
        } else if constexpr (_detail::is_clean_vector_v<ParseType>) {
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


};

#endif //LEETCODE_PARSE_HPP
