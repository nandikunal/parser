#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <spdlog/spdlog.h>
#include <boost/filesystem.hpp>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "text_output_impl.hpp"

namespace util
{
    TextOutputImpl::TextOutputImpl()
    {
        try
        {
            constexpr char filename[] = "output.txt";
            if(boost::filesystem::exists(filename))
            {
                boost::filesystem::remove_all(filename);
            }
            mFileLogger = spdlog::basic_logger_mt("file", filename);
            mFileLogger->set_pattern("%v");
        }
        catch (const spdlog::spdlog_ex &ex)
        {
            spdlog::error("file logger init failed {}", ex.what());
        }
    }

    void TextOutputImpl::write(const std::vector<std::pair<std::string, uint32_t>>& data)
    {
        for(auto&& val : data)
        {
            mFileLogger->info("{},{}", val.first, val.second);
        }
    }

    TextOutputImpl::~TextOutputImpl()
    {
        spdlog::drop("file");
    }
} // namespace util
