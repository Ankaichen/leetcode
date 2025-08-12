/**
 ******************************************************************************
 * @file           : leetcode_task200.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-8-12
 ******************************************************************************
 */

#include "../include/leetcode_task200.h"

static int numIslands3(std::vector<std::vector<char>>& grid) {
    // 并查集
    int size_i = grid.size(), size_j = grid[0].size();
    UnionFindIndex uf(size_i * size_j);
    int root_union = -1;
    for (int i = 0; i < size_i; ++i) {  // 遍历连接
        for (int j = 0; j < size_j; ++j) {
            if (grid[i][j] == '1') {
                root_union = i * size_j + j;
                uf.insert(i * size_j + j);
                int new_i, new_j;
                if ((new_i = i + 1) < size_i && grid[new_i][j] == '1') {
                    uf.insert(new_i * size_j + j);
                    uf.union_value(i * size_j + j, new_i * size_j + j);
                }
                if ((new_j = j + 1) < size_j && grid[i][new_j] == '1') {
                    uf.insert(i * size_j + new_j);
                    uf.union_value(i * size_j + j, i * size_j + new_j);
                }
            }
        }
    }
    if (root_union < 0) return 0;
    int island_count = 1;
    for (int i = 0; i < size_i; ++i) {  // 查找数量
        for (int j = 0; j < size_j; ++j) {
            if (grid[i][j] == '1') {
                if (!uf.in_same_union(root_union, i * size_j + j)) {
                    ++island_count;
                    uf.union_value(root_union, i * size_j + j);
                }
            }
        }
    }
    return island_count;
}

static int numIslands2(std::vector<std::vector<char>>& grid) {
    // 广搜
    if (grid.empty()) return 0;
    std::vector<std::vector<bool>> flag(grid.size(), std::vector<bool>(grid[0].size(), false));
    auto bfs = [&grid, &flag](int start_i, int start_j) -> void {
        int size_i = grid.size(), size_j = grid[0].size();
        if (start_i < 0 || start_i >= size_i || start_j < 0 || start_j >= size_j || flag[start_i][start_j] || grid[start_i][start_j] == '0') return;
        std::deque<std::pair<int, int>> queue{std::make_pair(start_i, start_j)};
        flag[start_i][start_j] = true;
        while (!queue.empty()) {
            auto [i, j] = queue.front();
            if (i > 0 && !flag[i - 1][j] && grid[i - 1][j] == '1') {
                flag[i - 1][j] = true;
                queue.push_back(std::make_pair(i - 1, j));
            }
            if (i < size_i - 1 && !flag[i + 1][j] && grid[i + 1][j] == '1') {
                flag[i + 1][j] = true;
                queue.push_back(std::make_pair(i + 1, j));
            }
            if (j > 0 && !flag[i][j - 1] && grid[i][j - 1] == '1') {
                flag[i][j - 1] = true;
                queue.push_back(std::make_pair(i, j - 1));
            }
            if (j < size_j - 1 && !flag[i][j + 1] && grid[i][j + 1] == '1') {
                flag[i][j + 1] = true;
                queue.push_back(std::make_pair(i, j + 1));
            }
            queue.pop_front();
        }
    };
    int size_i = grid.size(), size_j = grid[0].size();
    int island_count = 0;
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            if (grid[i][j] == '1' && !flag[i][j]) {
                ++island_count;
                bfs(i, j);
            }
        }
    }
    return island_count;
}

static int numIslands1(std::vector<std::vector<char>>& grid) {
    // 深搜
    if (grid.empty()) return 0;
    std::vector<std::vector<bool>> flag(grid.size(), std::vector<bool>(grid[0].size(), false));
    auto dfs = [&grid, &flag](auto& self, int start_i, int start_j) -> void {
        int size_i = grid.size(), size_j = grid[0].size();
        if (start_i < 0 || start_i >= size_i || start_j < 0 || start_j >= size_j || flag[start_i][start_j] || grid[start_i][start_j] == '0') return;
        flag[start_i][start_j] = true;
        if (start_i > 0 && !flag[start_i - 1][start_j] && grid[start_i - 1][start_j] == '1') self(self, start_i - 1, start_j);
        if (start_i < size_i - 1 && !flag[start_i + 1][start_j] && grid[start_i + 1][start_j] == '1') self(self, start_i + 1, start_j);
        if (start_j > 0 && !flag[start_i][start_j - 1] && grid[start_i][start_j - 1] == '1') self(self, start_i, start_j - 1);
        if (start_j < size_j - 1 && !flag[start_i][start_j + 1] && grid[start_i][start_j + 1] == '1') self(self, start_i, start_j + 1);
    };
    int size_i = grid.size(), size_j = grid[0].size();
    int island_count = 0;
    for (int i = 0; i < size_i; ++i) {
        for (int j = 0; j < size_j; ++j) {
            if (grid[i][j] == '1' && !flag[i][j]) {
                ++island_count;
                dfs(dfs, i, j);
            }
        }
    }
    return island_count;
}

int LeetcodeTask200::solve(const std::vector<std::vector<char>>& grid) const {
    return numIslands3(const_cast<std::vector<std::vector<char>>&>(grid));
}