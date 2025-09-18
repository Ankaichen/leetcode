/**
 ******************************************************************************
 * @file           : leetcode_task1610.cpp
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-9-18
 ******************************************************************************
 */

#include "../include/leetcode_task1610.h"

static int visiblePoints1(const std::vector<std::vector<int>>& points, int angle, const std::vector<int>& location) {
    // 转换为极坐标 然后使用双指针查找
    std::vector<double> points_angle;
    points_angle.reserve(points.size());
    int center_count = 0;
    constexpr double upx = 0., upy = 1., pi = 3.1415926, pi_2 = 2 * pi;
    double angle_rad = static_cast<double>(angle) / 360. * pi_2;
    for (const auto& point : points) {
        double vx = point[0] - location[0], vy = point[1] - location[1];
        double norm = vx * vx + vy * vy;
        if (norm < 1e-5) {  // 转换为极坐标表示 同时记录中心点的个数
            ++center_count;
        } else {
            double ang = std::acos((vx * upx + vy * upy) / std::sqrt(norm));
            if (vx < 0) ang = pi_2 - ang;  // 处理大于180的情况
            points_angle.push_back(ang);
        }
    }
    int max_count = 0;
    std::sort(points_angle.begin(), points_angle.end());
    for (int left = 0, right = 0; left < points_angle.size(); ++left) {
        bool flag = true;
        double diff = points_angle[right] - points_angle[left];
        if (diff < 0) diff = diff + pi_2;  // 双指针查找 flag用于区分是否转了一圈
        while ((diff < angle_rad || std::abs(diff - angle_rad) < 1e-5) && (flag || right != left)) {
            right = (right + 1) % points_angle.size();
            flag = false;
            diff = points_angle[right] - points_angle[left];
            if (diff < 0) diff = diff + pi_2;
        }
        if (!flag && right == left) {
            max_count = points_angle.size();
            break;
        }
        int count = (right - left + points_angle.size()) % points_angle.size();
        max_count = std::max(max_count, count);
    }
    return max_count + center_count;
}

int LeetcodeTask1610::solve(const std::vector<std::vector<int>>& points, int angle, const std::vector<int>& location) const {
    return visiblePoints1(points, angle, location);
}