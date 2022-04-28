#include <vector>
#include <string>
#include "test_text_parser.hpp"
#include "output_interface.hpp"
#include "xml_output_impl.hpp"
#include "text_output_impl.hpp"
#include "console_output_impl.hpp"

TEST_F(TestTextParser, checkComputeWords)
{
    std::string str = "Hello, I am testing :-)";
    auto data = mParser.computeWords(str, std::string("(\\w+)"));
    EXPECT_TRUE(!data.empty());

    util::IOutput* iopConsole = new util::ConsoleOutputImpl();
    iopConsole->write(data);
    delete iopConsole;
    iopConsole = nullptr;

    util::IOutput* iopText= new util::TextOutputImpl();
    iopText->write(data);
    delete iopText;
    iopText = nullptr;
    
    util::IOutput* iopXml = new util::XmlOutputImpl();
    iopXml->write(data);
    delete iopXml;
    iopXml = nullptr;
}

TEST_F(TestTextParser, checkComputeSmileys)
{
    std::string str = "Hello, I am testing :-)\
    Hello again! Testing.";
    auto data = mParser. computeSmileys(str, std::string(":-?(\\]|\\[|\\)|\\()"));
    EXPECT_TRUE(!data.empty());

    util::IOutput* iopConsole = new util::ConsoleOutputImpl();
    iopConsole->write(data);
    delete iopConsole;
    iopConsole = nullptr;

    util::IOutput* iopText= new util::TextOutputImpl();
    iopText->write(data);
    delete iopText;
    iopText = nullptr;
    
    util::IOutput* iopXml = new util::XmlOutputImpl();
    iopXml->write(data);
    delete iopXml;
    iopXml = nullptr;
}

TEST_F(TestTextParser, checkComputeWordsFailCase)
{
    std::string str = "&)(!@!##!$#%$^";
    auto data = mParser.computeWords(str, std::string("(\\w+)"));
    EXPECT_TRUE(data.empty());
}

TEST_F(TestTextParser, checkComputeSmileysFailCase)
{
    std::string str = ":-{";
    auto data = mParser. computeSmileys(str, std::string(":-?(\\]|\\[|\\)|\\()"));
    EXPECT_TRUE(data.empty());
}

TEST_F(TestTextParser, checkComputeWordsFailRegex)
{
    std::string str = "&)(!@!##!$#%$^";
    auto data = mParser.computeWords(str, std::string("(\\w+"));
    EXPECT_TRUE(data.empty());
}

TEST_F(TestTextParser, checkComputeSmileysFailRegex)
{
    std::string str = ":-{";
    auto data = mParser. computeSmileys(str, std::string(":-?(\\]|\\[|\\)|\\("));
    EXPECT_TRUE(data.empty());
}
