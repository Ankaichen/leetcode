/**
 ******************************************************************************
 * @file           : delete.hpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-4-20
 ******************************************************************************
 */

#ifndef LEETCODE_DELETE_HPP
#define LEETCODE_DELETE_HPP

#include <type_traits>

#include "../tasks/core/utils.h"

namespace Delete {

    namespace _detail {

        static void deleteListNode(ListNode *listNode) {
            ListNode *p = listNode;
            while (listNode != nullptr) {
                p = listNode->next;
                delete listNode;
                listNode = p;
            }
        }

    }  // namespace _detail

    template<typename T>
    static void deleteValue(T &value) {
        using DeleteType = std::remove_cvref_t<T>;
        if constexpr (!std::is_pointer_v<DeleteType>) {
            return;
        }
        if constexpr (std::is_same_v<DeleteType, ListNode *>) {
            _detail::deleteListNode(value);
        }
    }
}  // namespace Delete

#endif  // LEETCODE_DELETE_HPP
