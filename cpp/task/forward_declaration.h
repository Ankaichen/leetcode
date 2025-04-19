/**
  ******************************************************************************
  * @file           : forward_declaration.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-4-19
  ******************************************************************************
  */

#ifndef LEETCODE_FORWARD_DECLARATION_H
#define LEETCODE_FORWARD_DECLARATION_H

#include <memory>
#include <utility>

template<unsigned int ID, typename Func>
class Task;


template<unsigned int ID, typename Res, typename... Args>
class Task<ID, Res(Args...)>;

template<typename T>
class TaskRunner;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //LEETCODE_FORWARD_DECLARATION_H
