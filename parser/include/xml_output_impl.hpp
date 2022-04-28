#pragma once

#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <boost/property_tree/ptree.hpp>
#include "output_interface.hpp"

namespace util
{
    /*!
    * This class Implements XML file output of parsed Text Block
    */
    class XmlOutputImpl : public IOutput
    {
    public:
        /*!
        * Constructor
        */
        XmlOutputImpl() = default;

        /*!
        * Destructor
        */
        ~XmlOutputImpl() = default;

        /*!
        * Parsed Text Block output will be logged on XML file.
        */
        void write(std::vector<std::pair<std::string, uint32_t>> data) override;
    private:
        boost::property_tree::ptree mPtree;
    };
} // namespace util
