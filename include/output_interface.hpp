#pragma once

#include <string>
#include <vector>
#include <utility>
#include <cstdint>

namespace util
{
    /*!
    * Abstract class for output of parsed Text Block
    */
    class IOutput
    {
    public:
        /*!
        * Constructor
        */
        IOutput() = default;

        /*!
        * Destructor
        */
        virtual ~IOutput(){};

        /*!
        * Interface to write output on console/text file/xml.
        */
        virtual void write(std::vector<std::pair<std::string, uint32_t>> data) = 0;
    };
} // namespace util
