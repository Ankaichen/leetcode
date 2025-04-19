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


template<unsigned int ID, typename Func>
class Task;


template<unsigned int ID, typename Res, typename... Args>
class Task<ID, Res(Args...)>;

template<typename T>
class TaskRunner;


#endif //LEETCODE_FORWARD_DECLARATION_H
