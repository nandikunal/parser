#pragma once

#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <spdlog/spdlog.h>
#include "output_interface.hpp"

namespace util
{
    /*!
    * This class Implements console output of parsed Text Block
    */
    class ConsoleOutputImpl : public IOutput
    {
    public:
        /*!
        * Constructor
        */
        ConsoleOutputImpl();

        /*!
        * Destructor
        */
       ~ConsoleOutputImpl();

        /*!
        * Parsed Text Block output will be logged on console.
        */
        void write(const std::vector<std::pair<std::string, uint32_t>>& data) override;

    private:
        std::shared_ptr<spdlog::logger> mConsoleLogger;
    };
} // namespace util
