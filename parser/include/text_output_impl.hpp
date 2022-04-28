#pragma once

#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include "spdlog/spdlog.h"
#include "output_interface.hpp"

namespace util
{
    /*!
    * This class Implements Text file output of parsed Text Block
    */
    class TextOutputImpl : public IOutput
    {
    public:
        /*!
        * Constructor
        */
        TextOutputImpl();
        
        /*!
        * Destructor
        */
        ~TextOutputImpl();

        /*!
        * Parsed Text Block output will be logged on text file.
        */
        void write(std::vector<std::pair<std::string, uint32_t>> data) override;
    private:
        std::shared_ptr<spdlog::logger> mFileLogger;
    };
} // namespace util
