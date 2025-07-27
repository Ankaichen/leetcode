file(GLOB_RECURSE TASKS task_impl/source/*.cpp)

add_library(
        tasksLib ${TASKS}
)