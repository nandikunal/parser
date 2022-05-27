#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "console_output_impl.hpp"

namespace util
{
    ConsoleOutputImpl::ConsoleOutputImpl()
    {
        try
        {
            mConsoleLogger = spdlog::stdout_color_mt("console");
            mConsoleLogger->set_pattern("%v");
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            spdlog::error("console logger init failed {}", ex.what());
        }
    }

    void ConsoleOutputImpl::write(const std::vector<std::pair<std::string, uint32_t>>& data)
    {
        for(auto&& val : data)
        {
            mConsoleLogger->info("{},{}", val.first, val.second);
        }
    }

    ConsoleOutputImpl::~ConsoleOutputImpl()
    {
        spdlog::drop("console");
    }
} // namespace util
