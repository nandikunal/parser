#pragma once

#include <gtest/gtest.h>
#include "text_parser.hpp"

class TestTextParser : public ::testing::Test
{
public:
    TestTextParser(void) = default;
    virtual ~TestTextParser(void) = default;

    void SetUp(void) override {}
    void TearDown(void) override {}

    util::TextParser mParser;
};
