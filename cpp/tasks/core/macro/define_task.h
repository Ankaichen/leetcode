/**
  ******************************************************************************
  * @file           : define_task.h
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-8-2
  ******************************************************************************
  */

#ifdef TASK_DEFINITION_SHOULD_END
#error "must end task definition"
#else

// using_LeetCodeTestCaseReader

#ifdef using_LeetCodeTestCaseReader
#define getReaderType(RES, ARGS...) LeetCodeTestCaseReader<RES(ARGS)>
#endif

// using_NormalTestResultProcessor
// using_ListNodeTestResultProcessor
// using_UnorderedTestResultProcessor

#ifdef using_NormalTestResultProcessor
#define getProcessorType(RES) NormalTestResultProcessor<RES>
#endif
#ifdef using_ListNodeTestResultProcessor
#define getProcessorType(RES) ListNodeTestResultProcessor
#endif
#ifdef using_UnorderedTestResultProcessor
#define getProcessorType(RES) UnorderedTestResultProcessor<RES>
#endif

//#ifdef using_NormalTestResultProcessor
#define DEFINE_TASK(TASK_NAME, NAME, RES, ARGS...)                                                    \
    inline const char TASK_NAME##_name[] = NAME;                                                      \
    class TASK_NAME : public Task<TASK_NAME##_name, getReaderType(RES, ARGS), getProcessorType(RES), RES(ARGS)> { \
    public:                                                                                           \
        TASK_NAME() = default;                                                                        \
        ~TASK_NAME() noexcept override = default;                                                     \
        INIT_TESTCASE_FILE_NAME                                                                       \
        [[nodiscard]] RES solve(ARGS) const override;                                                 \
    }
//#endif

#include "../../core/task.hpp"
#include "../../core/test_case_reader.hpp"
#include "../../core/test_result_processor.hpp"

#define TASK_DEFINITION_SHOULD_END

#endif // TASK_DEFINITION_SHOULD_END
