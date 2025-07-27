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

#include <unordered_map>
#include <unordered_set>
#include <vector>
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

template<typename T>
class UnionFind {
public:
    UnionFind() = default;

    void insert(const T &value) {
        auto iter = this->_data.find(value);
        if (iter != this->_data.end()) return;
        std::size_t index = this->_sizes.size();
        this->_data.insert(std::make_pair(value, index));
        this->_dataParent.push_back(index);
        this->_sizes.push_back(1);
    }

    void union_value(const T &v1, const T &v2) {
        int index1 = this->find_root_index(v1), index2 = this->find_root_index(v2);
        if (index1 == index2 || index1 == -1 || index2 == -1)
            return;
        int size1 = this->_sizes[index1], size2 = this->_sizes[index2];
        if (size1 < size2) {
            std::swap(index1, index2);
        }
        this->_dataParent[index2] = index1;
        this->_sizes[index1] = size1 + size2;
    }

    bool in_same_union(const T &v1, const T &v2) {
        int index1 = this->find_root_index(v1);
        int index2 = this->find_root_index(v2);
        if (index1 == -1 || index2 == -1) {
            return false;
        }
        return index1 == index2;
    }

    std::size_t union_size(const T &value) {
        return this->_sizes[this->find_root_index(value)];
    }

private:
    int find_root_index(const T &value) {
        auto iter = this->_data.find(value);
        if (iter == this->_data.end()) return -1;
        std::size_t i = iter->second;
        for (; this->_dataParent[i] != i; i = this->_dataParent[i]);
        this->_dataParent[iter->second] = i;
        return i;
    }

private:

    std::unordered_map<T, std::size_t> _data{};
    std::vector<std::size_t> _dataParent{};
    std::vector<int> _sizes{};
};

template<typename T>
class UnionFindIndex {
public:
    UnionFindIndex() = default;

    explicit UnionFindIndex(std::size_t length) : _dataParent(length, 0), _sizes(length, 1) {
        for (int i = 0; i < length; ++i) {
            _dataParent[i] = i;
        }
    }

    void insert(const T &value) {
        if (value < this->_dataParent.size())
            return;
        std::size_t size = this->_dataParent.size();
        this->_dataParent.resize(value);
        for (std::size_t i = size; i < this->_dataParent.size(); ++i) {
            this->_dataParent[i] = i;
            this->_sizes[i] = 1;
        }
    }

    void union_value(const T &v1, const T &v2) {
        int index1 = this->find_root_index(v1), index2 = this->find_root_index(v2);
        if (index1 == index2 || index1 == -1 || index2 == -1)
            return;
        int size1 = this->_sizes[index1], size2 = this->_sizes[index2];
        if (size1 < size2) {
            std::swap(index1, index2);
        }
        this->_dataParent[index2] = index1;
        this->_sizes[index1] = size1 + size2;
    }

    bool in_same_union(const T &v1, const T &v2) {
        int index1 = this->find_root_index(v1), index2 = this->find_root_index(v2);
        if (index1 == -1 || index2 == -1) {
            return false;
        }
        return index1 == index2;
    }

    std::size_t union_size(const T &value) {
        return this->_sizes[this->find_root_index(value)];
    }

private:
    int find_root_index(const T &value) {
        if (value >= this->_dataParent.size())
            return -1;
        std::size_t i = value;
        for (; this->_dataParent[i] != i; i = this->_dataParent[i]);
        this->_dataParent[value] = i;
        return static_cast<int>(i);
    }

    std::vector<std::size_t> _dataParent{};
    std::vector<int> _sizes{};
};


#endif //LEETCODE_FORWARD_DECLARATION_H
