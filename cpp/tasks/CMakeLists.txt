# file(GLOB_RECURSE TASKS task_impl/source/*.cpp)
file(GLOB_RECURSE TASKS task_impl/source/task1.cpp)

file(GLOB TASK_INPUT
        ${CMAKE_CURRENT_SOURCE_DIR}/task_input)

file(COPY ${TASK_INPUT} DESTINATION ${CMAKE_BINARY_DIR})

add_library(
       tasksLib ${TASKS}
)