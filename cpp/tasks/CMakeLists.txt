file(GLOB_RECURSE TASKS ./source/*.cpp)

add_library(
        tasksLib ${TASKS}
)