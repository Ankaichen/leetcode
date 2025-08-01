

#define LEETCODE_TESTCASE_READER

#if defined(LEETCODE_TESTCASE_READER)

#define getReaderType(RES, ARGS) LeetCodeTestCaseReader<RES(ARGS)>

#endif

#define DEFINE_TASK(TASK_NAME, NAME, RES, ARGS) \
                                                \
    static constexpr char Name[] = NAME;        \
    class TASK_NAME : public Task<Name, getReaderType(RES, ARGS)>

#undef DEFINE_TASK

#include "../../core/task.hpp"
#include "../../core/test_case_reader.hpp"
#include "../../core/test_result_processor.hpp"