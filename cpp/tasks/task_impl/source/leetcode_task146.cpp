/**
 ******************************************************************************
 * @file           : leetcode_task146.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-9-20
 ******************************************************************************
 */

#include "../include/leetcode_task146.h"

class LRUCache1 {
    struct CacheItem {
        int value;
        int time;
    };
public:
    explicit LRUCache1(int capacity) : _capacity(capacity), _global_time(0), _data{} {
    }

    int get(int key) {
        auto iter = this->_data.find(key);
        if (iter == this->_data.end()) {
            return -1;
        } else {
            iter->second.time = this->update_global_time();
            return iter->second.value;
        }
    }

    void put(int key, int value) {
        if (this->put_judge_remove(key, value)) {
            this->remove_time_min();
        }
    }

private:
    int update_global_time() {
        return _global_time++;
    }

    void remove_time_min() {
        auto min_iter = this->_data.begin();
        for (auto i = this->_data.begin(); i != this->_data.end(); ++i) {
            if (min_iter->second.time > i->second.time) {
                min_iter = i;
            }
        }
        this->_data.erase(min_iter);
    }

    bool put_judge_remove(int key, int value) {
        auto iter = this->_data.find(key);
        if (iter == this->_data.end()) {
            this->_data.insert(std::make_pair(key, CacheItem{value, this->update_global_time()}));
            return this->_data.size() > this->_capacity;
        } else {
            iter->second.value = value;
            iter->second.time = this->update_global_time();
            return false;
        }
    }

private:
    int _capacity;
    int _global_time;
    std::map<int, CacheItem> _data;
};

using LRUCache = LRUCache1;

std::vector<std::string>
LeetcodeTask146::solve(const std::vector<std::string> &input1, const std::vector<std::vector<int>> &input2) const {
    LRUCache *cache = nullptr;
    std::vector<std::string> result;
    for (int i = 0; i < input1.size(); ++i) {
        const std::string &i1 = input1[i];
        const std::vector<int> &i2 = input2[i];
        std::stringstream ss;
        if (i1 == "LRUCache") {
            cache = new LRUCache(i2[0]);
            ss << "null";
        } else if (i1 == "get") {
            assert(cache != nullptr);
            ss << cache->get(i2[0]);
        } else if (i1 == "put") {
            assert(cache != nullptr);
            cache->put(i2[0], i2[1]);
            ss << "null";
        }
        result.emplace_back(ss.str());
    }
    delete cache;
    return result;
}
