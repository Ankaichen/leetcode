/**
  ******************************************************************************
  * @file           : leetcode_task130.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/leetcode_task130.h"

static void solve1(std::vector<std::vector<char>>& board) {
    if (board.empty())
        return;
    UnionFind<int> uf;
    int m = board.size(), n = board[0].size();
    std::vector<int> edge;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            uf.insert(i * n + j);
            if (board[i][j] == 'O' &&
                (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                edge.push_back(i * n + j);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 'O')
                continue;
            if (i + 1 < m && board[i + 1][j] == 'O')
                uf.union_value((i + 1) * n + j, i * n + j);
            if (j + 1 < n && board[i][j + 1] == 'O')
                uf.union_value(i * n + j + 1, i * n + j);
        }
    }
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (board[i][j] != 'O')
                continue;
            bool edge_flag = false;
            for (int k = 0; k < edge.size(); ++k) {
                if (uf.in_same_union(i * n + j, edge[k])) {
                    edge_flag = true;
                    break;
                }
            }
            if (!edge_flag) {
                board[i][j] = 'X';
            }
        }
    }
}

static void solve2(std::vector<std::vector<char>>& board) {
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();
    UnionFindIndex<int> uf(m * n);
    std::vector<int> edge;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 'O')
                continue;
            if (i + 1 < m && board[i + 1][j] == 'O')
                uf.union_value((i + 1) * n + j, i * n + j);
            if (j + 1 < n && board[i][j + 1] == 'O')
                uf.union_value(i * n + j + 1, i * n + j);
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                edge.push_back(i * n + j);
            }
        }
    }
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (board[i][j] != 'O')
                continue;
            bool edge_flag = false;
            for (int k : edge) {
                if (uf.in_same_union(i * n + j, k)) {
                    edge_flag = true;
                    break;
                }
            }
            if (!edge_flag) {
                board[i][j] = 'X';
            }
        }
    }
}

static void dfs(const std::vector<std::vector<char>>& board, int starti, int startj,
         std::vector<std::vector<bool>> &flags) {
    flags[starti][startj] = true;
    std::size_t size = board.size();
    int upi = starti - 1, downi = starti + 1, leftj = startj - 1,
            rightj = startj + 1;
    if (upi >= 0 && board[upi][startj] == 'O' && !flags[upi][startj]) { // up
        dfs(board, upi, startj, flags);
    }
    if (rightj < board[0].size() && board[starti][rightj] == 'O' && !flags[starti][rightj]) { // right
        dfs(board, starti, rightj, flags);
    }
    if (downi < board.size() && board[downi][startj] == 'O' && !flags[downi][startj]) { // down
        dfs(board, downi, startj, flags);
    }
    if (leftj >= 0 && board[starti][leftj] == 'O' && !flags[starti][leftj]) { // left
        dfs(board, starti, leftj, flags);
    }
}

static void solve3(std::vector<std::vector<char>>& board) {
    if (board.empty())
        return;
    int m = board.size(), n = board[0].size();
    std::vector<std::vector<bool>> flags(m, std::vector<bool>(n, false));
    for (int i = 0; i < n; ++i) {
        if (board[0][i] == 'O') {
            dfs(board, 0, i, flags);
        }
        if (board[m-1][i] == 'O') {
            dfs(board, m-1, i, flags);
        }
    }
    for (int i = 1; i < m; ++i) {
        if (board[i][0] == 'O') {
            dfs(board, i, 0, flags);
        }
        if (board[i][n-1] == 'O') {
            dfs(board, i, n-1, flags);
        }
    }
    for (int i = 1; i < m-1; ++i) {
        for (int j = 1; j < n-1; ++j) {
            if (!flags[i][j]) {
                board[i][j] = 'X';
            }
        }
    }
}

std::vector<std::vector<char>> LeetcodeTask130::solve(const std::vector<std::vector<char>> &board) const {
    solve3(const_cast<std::vector<std::vector<char>> &>(board));
    return board;
}