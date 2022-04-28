#include <spdlog/spdlog.h>
#include "output_factory.hpp"
#include "xml_output_impl.hpp"
#include "text_output_impl.hpp"
#include "console_output_impl.hpp"

namespace util
{
    std::vector<std::shared_ptr<util::IOutput>> OutputFactory::createOutput(const util::OutputType type)
    {
        switch (type)
        {
        case OutputType::ALL:
        {
            mOutputList.emplace_back(std::make_shared<ConsoleOutputImpl>());
            mOutputList.emplace_back(std::make_shared<TextOutputImpl>());
            mOutputList.emplace_back(std::make_shared<XmlOutputImpl>());
        }
        break;
        case OutputType::CONSOLE_TEXT:
        {
            mOutputList.emplace_back(std::make_shared<ConsoleOutputImpl>());
            mOutputList.emplace_back(std::make_shared<TextOutputImpl>());
        }
        break;
        case OutputType::CONSOLE_XML:
        {
            mOutputList.emplace_back(std::make_shared<ConsoleOutputImpl>());
            mOutputList.emplace_back(std::make_shared<XmlOutputImpl>());
        }
        break;
        case OutputType::TEXT_XML:
        {
            mOutputList.emplace_back(std::make_shared<TextOutputImpl>());
            mOutputList.emplace_back(std::make_shared<XmlOutputImpl>());
        }
        break;
        case OutputType::TEXT:
        {
            mOutputList.emplace_back(std::make_shared<TextOutputImpl>());
        }
        break;
        case OutputType::XML:
        {
            mOutputList.emplace_back(std::make_shared<XmlOutputImpl>());
        }
        break;
        case OutputType::CONSOLE:
        default:
        {
            mOutputList.emplace_back(std::make_shared<ConsoleOutputImpl>());
        }
        break;
        }
        return mOutputList;
    }
} // namespace util
