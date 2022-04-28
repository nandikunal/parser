#pragma once

#include <gtest/gtest.h>
#include "output_factory.hpp"

class TestOutputFactory : public ::testing::Test
{
public:
    TestOutputFactory(void) = default;
    virtual ~TestOutputFactory(void) = default;

    void SetUp(void) override {}
    void TearDown(void) override {}
};
