#include <string>
#include <vector>
#include <utility>
#include <cstdint>
#include <spdlog/spdlog.h>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include "xml_output_impl.hpp"

namespace util
{
    void XmlOutputImpl::write(std::vector<std::pair<std::string, uint32_t>> data)
    {
        namespace pt = boost::property_tree;

        std::string textInfo = "TextInfo";
        mPtree.put(textInfo, "");
        
        for(auto &&val : data) {
            auto node = textInfo + ".data";
            mPtree.add(node, val.first + "," + std::to_string(val.second));
        }

        constexpr char filename[] = "output.xml";
        try
        {
            if(boost::filesystem::exists(filename))
            {
                boost::filesystem::remove_all(filename);
            }

            pt::write_xml(filename, mPtree);
        }
        catch(const std::exception& e)
        {
            spdlog::error("Excption caught in {} {}", __PRETTY_FUNCTION__, e.what());
        }
    }
} // namespace util
