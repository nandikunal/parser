#pragma once

#include <string>
#include <vector>
#include <utility>
#include <cstdint>

namespace util
{
    /*!
    * This class implements Text Block parser
    */
    class TextParser final
    {
    public:
        /*!
        * Constructor
        */
        TextParser() = default;

        /*!
        * Destructor
        */
        ~TextParser() = default;

        /*!
        * Parsed Text Block to compute top used words.
        * @param string Text Block
        * @return list of pair of word and number of times it is used.
        */
        std::vector<std::pair<std::string, uint32_t>> computeWords(const std::string &buffer, const std::string& regex);

        /*!
        * Parsed Text Block to compute get smiley index.
        * @param string Text Block
        * @return list of pair of smiley and start index.
        */
        std::vector<std::pair<std::string, uint32_t>> computeSmileys(const std::string &buffer, const std::string& regex);
    };
} // namespace util
