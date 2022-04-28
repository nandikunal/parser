#include <vector>
#include <memory>
#include "test_output_factory.hpp"
#include "output_interface.hpp"

TEST_F(TestOutputFactory, checkFactoryCreateConsole)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::CONSOLE);
    EXPECT_TRUE(!data.empty());
}

TEST_F(TestOutputFactory, checkFactoryCreateText)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::TEXT);
    EXPECT_TRUE(!data.empty());
}

TEST_F(TestOutputFactory, checkFactoryCreateXml)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::XML);
    EXPECT_TRUE(!data.empty());
}

TEST_F(TestOutputFactory, checkFactoryCreateConsoleText)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::CONSOLE_TEXT);
    EXPECT_TRUE(!data.empty());
    EXPECT_TRUE(2 == data.size());
}

TEST_F(TestOutputFactory, checkFactoryCreateConsoleXml)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::CONSOLE_XML);
    EXPECT_TRUE(!data.empty());
    EXPECT_TRUE(2 == data.size());
}

TEST_F(TestOutputFactory, checkFactoryCreateTextXml)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::TEXT_XML);
    EXPECT_TRUE(!data.empty());
    EXPECT_TRUE(2 == data.size());
}

TEST_F(TestOutputFactory, checkFactoryCreateAll)
{
    util::OutputFactory factory;
    auto data = factory.createOutput(util::OutputType::ALL);
    EXPECT_TRUE(!data.empty());
    EXPECT_TRUE(3 == data.size());
}
