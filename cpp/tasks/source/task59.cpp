/**
  ******************************************************************************
  * @file           : task59.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-6-19
  ******************************************************************************
  */

#include "../include/task59.h"

Task59::Task59() {
    this->addTestCase("n = 1", "[[1]]");
    this->addTestCase("n = 2", "[[1,2],[4,3]]");
    this->addTestCase("n = 3", "[[1,2,3],[8,9,4],[7,6,5]]");
//    this->addTestCase("n = 4", "[[1,2,3,4],[12,13,14,5],[11,16,15,6],[10,9,8,7]]");
//    this->addTestCase("n = 5", "[[1,2,3,4,5],[16,17,18,19,6],[15,24,25,20,7],[14,23,22,21,8],[13,12,11,10,9]]");
}

enum class Direction {
    RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3
};

static void nextIndex(const std::vector<std::vector<int> > &res, int &i, int &j, Direction &dir, bool changeDirection) {
    if (changeDirection) {
        dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
    }
    switch (dir) {
        case Direction::RIGHT:
            ++j;
            break;
        case Direction::DOWN:
            ++i;
            break;
        case Direction::LEFT:
            --j;
            break;
        case Direction::UP:
            --i;
            break;
        default:
            break;
    }
}

static std::vector<std::vector<int>> generateMatrix1(int n) {
    auto result = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    // 标记所有需要改变方向的点
    for (int i = 0; i < (n + 1) / 2; ++i) { // 每次循环外侧一圈
        result[i][n - i - 1] = -1; // 右上
        result[n - i - 1][i] = -1; // 左下
        result[n - i - 1][n - i - 1] = -1; // 右下
        if (i >= 1) { // 转到下一圈的位置
            result[i][i - 1] = -1;
        }
    }
    Direction dir = Direction::RIGHT;
    bool changeDirection = false;
    for (int index = 1, i = 0, j = 0, max_index = n * n; // 根据标记遍历
         index <= max_index; ++index, nextIndex(result, i, j, dir, changeDirection)) {
        changeDirection = (result[i][j] == -1);
        result[i][j] = index;
    }
    return result;
}

static std::vector<std::vector<int>> generateMatrix2(int n) {
    auto result = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    int loop = n / 2;
    int startI = 0, startJ = 0;
    int edgeLen = n - 1;
    int value = 1;
    while (loop) {
        int i = startI, j = startJ;
        for (; j < edgeLen; ++j) // 上边
            result[i][j] = value++;
        for (; i < edgeLen; ++i) // 右边
            result[i][j] = value++;
        for (; j > n - edgeLen - 1; --j) // 下边
            result[i][j] = value++;
        for (; i > n - edgeLen - 1; --i) // 左边
            result[i][j] = value++;
        ++startI;
        ++startJ;
        --edgeLen;
        --loop;
    }
    if (n % 2 == 1) { // 奇数计算中心点
        result[n / 2][n / 2] = value;
    }
    return result;
}

std::vector<std::vector<int>> Task59::solve(int n) const {
    return generateMatrix2(n);
}