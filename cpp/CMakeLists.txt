cmake_minimum_required(VERSION 3.30)
project(leetcode
        VERSION 1.0.0
        DESCRIPTION "LeetCode Solutions"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_executable(leetcode main.cpp)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:/Od>       # Disable optimization
            $<$<CONFIG:Release>:/O2>     # Optimize for speed
    )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:-O0 -g>    # No optimization, include debug symbols
            $<$<CONFIG:Release>:-O3>     # High optimization level
    )
endif ()

