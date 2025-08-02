/**
  ******************************************************************************
  * @file           : core.cpp
  * @author         : An Kaichen
  * @brief          : None
  * @attention      : None
  * @date           : 25-8-2
  ******************************************************************************
  */

#include "./test_result_processor.hpp"

ListNodeTestResultProcessor::CleanOutputType ListNodeTestResultProcessor::processResult(
        const ListNodeTestResultProcessor::CleanInputType &input) const {
    CleanOutputType output = input;
    const_cast<CleanInputType &>(input) = nullptr;
    return output;
}
