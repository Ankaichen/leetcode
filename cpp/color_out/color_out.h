/**
 ******************************************************************************
 * @file           : color_out.h
 * @author         : An Kaichen
 * @brief          : None
 * @attention      : None
 * @date           : 25-4-19
 ******************************************************************************
 */

#ifndef LEETCODE_COLOR_OUT_H
#define LEETCODE_COLOR_OUT_H

#include <iostream>
#include <string>

namespace ColorOut {
    /**
     * Foreground colors
     */
    enum class FG : int {
        Default = 39,
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        LightGray = 37,
        DarkGray = 90,
        LightRed = 91,
        LightGreen = 92,
        LightYellow = 93,
        LightBlue = 94,
        LightMagenta = 95,
        LightCyan = 96,
        White = 97
    };

    /**
     * Background colors
     */
    enum class BG : int {
        Default = 49,
        Black = 40,
        Red = 41,
        Green = 42,
        Yellow = 43,
        Blue = 44,
        Magenta = 45,
        Cyan = 46,
        LightGray = 47,
        DarkGray = 100,
        LightRed = 101,
        LightGreen = 102,
        LightYellow = 103,
        LightBlue = 104,
        LightMagenta = 105,
        LightCyan = 106,
        White = 107
    };

    /**
     * Modifier holds arbitrary ANSI code sequence
     */
    class TextStyle {
        friend std::ostream &operator<<(std::ostream &os, const TextStyle &ts);

        friend TextStyle Fg(FG color);

        friend TextStyle Bg(BG color);

        friend TextStyle Reset();

        friend TextStyle color(FG f, BG b);

    private:
        explicit TextStyle(std::string code) : _codes(std::move(code)) {}

    private:
        std::string _codes;
    };

    /**
     * Stream insertion operator sends the escape sequence
     * @param os std::ostream
     * @param ts TextStyle
     * @return   std::ostream
     */
    inline std::ostream &operator<<(std::ostream &os, const TextStyle &ts) { return os << "\033[" << ts._codes << "m"; }

    // Factory functions for single codes
    inline TextStyle Fg(FG color) { return TextStyle(std::to_string(static_cast<int>(color))); }

    inline TextStyle Bg(BG color) { return TextStyle(std::to_string(static_cast<int>(color))); }

    inline TextStyle Reset() { return TextStyle("0"); }

    // Combined foreground+background
    inline TextStyle color(FG f, BG b) { return TextStyle(std::to_string(static_cast<int>(f)) + ";" + std::to_string(static_cast<int>(b))); }

    inline const TextStyle reset = Reset();

    inline const TextStyle default_fg = Fg(FG::Default);
    inline const TextStyle black_fg = Fg(FG::Black);
    inline const TextStyle red_fg = Fg(FG::Red);
    inline const TextStyle green_fg = Fg(FG::Green);
    inline const TextStyle yellow_fg = Fg(FG::Yellow);
    inline const TextStyle blue_fg = Fg(FG::Blue);
    inline const TextStyle magenta_fg = Fg(FG::Magenta);
    inline const TextStyle cyan_fg = Fg(FG::Cyan);
    inline const TextStyle lightGray_fg = Fg(FG::LightGray);
    inline const TextStyle darkGray_fg = Fg(FG::DarkGray);
    inline const TextStyle lightRed_fg = Fg(FG::LightRed);
    inline const TextStyle lightGreen_fg = Fg(FG::LightGreen);
    inline const TextStyle lightYellow_fg = Fg(FG::LightYellow);
    inline const TextStyle lightBlue_fg = Fg(FG::LightBlue);
    inline const TextStyle lightMagenta_fg = Fg(FG::LightMagenta);
    inline const TextStyle lightCyan_fg = Fg(FG::LightCyan);
    inline const TextStyle white_fg = Fg(FG::White);

    inline const TextStyle default_bg = Bg(BG::Default);
    inline const TextStyle black_bg = Bg(BG::Black);
    inline const TextStyle red_bg = Bg(BG::Red);
    inline const TextStyle green_bg = Bg(BG::Green);
    inline const TextStyle yellow_bg = Bg(BG::Yellow);
    inline const TextStyle blue_bg = Bg(BG::Blue);
    inline const TextStyle magenta_bg = Bg(BG::Magenta);
    inline const TextStyle cyan_bg = Bg(BG::Cyan);
    inline const TextStyle lightGray_bg = Bg(BG::LightGray);
    inline const TextStyle darkGray_bg = Bg(BG::DarkGray);
    inline const TextStyle lightRed_bg = Bg(BG::LightRed);
    inline const TextStyle lightGreen_bg = Bg(BG::LightGreen);
    inline const TextStyle lightYellow_bg = Bg(BG::LightYellow);
    inline const TextStyle lightBlue_bg = Bg(BG::LightBlue);
    inline const TextStyle lightMagenta_bg = Bg(BG::LightMagenta);
    inline const TextStyle lightCyan_bg = Bg(BG::LightCyan);
    inline const TextStyle white_bg = Bg(BG::White);

}  // namespace ColorOut

#endif  // LEETCODE_COLOR_OUT_H
