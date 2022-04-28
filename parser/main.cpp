#include <string>
#include <fstream>
#include <iterator>
#include <spdlog/spdlog.h>
#include <boost/filesystem.hpp>
#include "text_parser.hpp"
#include "output_factory.hpp"
#include "output_interface.hpp"

int main(int argc, const char *argv[])
{
    if (argc != 3)
    {
        spdlog::warn("Re-run with {} <OutputType> <InputTextFile> to get desired output.", argv[0]);
        spdlog::info("*** OutputType ***");
        spdlog::info("* CONSOLE        0");
        spdlog::info("* TEXT           1");
        spdlog::info("* XML            2");
        spdlog::info("* CONSOLE_TEXT   3");
        spdlog::info("* CONSOLE_XML    4");
        spdlog::info("* TEXT_XML       5");
        spdlog::info("* ALL            6");
        return EXIT_FAILURE;
    }

    try
    {
        //TODO: add class to extend input file operation
        std::string filename(argv[2]);
        if (!boost::filesystem::exists(filename))
        {
            spdlog::warn("Mentioned {} doesn't exists, please provide valid file.", filename);
            return EXIT_FAILURE;
        }

        auto outputType = std::stoi(argv[1]);
        util::OutputFactory factory;
        auto &&outputList = factory.createOutput(static_cast<util::OutputType>(outputType));

        util::TextParser textParser;
        std::ifstream ifs(filename);
        std::string textBlock(std::istreambuf_iterator<char>{ifs}, {});

        for (auto &&op : outputList)
        {
            op->write(textParser.computeSmileys(textBlock, std::string(":-?(\\]|\\[|\\)|\\()")));
            op->write(textParser.computeWords(textBlock, std::string("(\\w+)")));
        }
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        spdlog::error("Invalid argument caught {}", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_FAILURE;
}
