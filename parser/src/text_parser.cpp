#include <map>
#include <set>
#include <regex>
#include <vector>
#include <string>
#include <utility>
#include <spdlog/spdlog.h>
#include "text_parser.hpp"

namespace util
{
    std::vector<std::pair<std::string, uint32_t>> TextParser::computeWords(const std::string &buffer, const std::string& regex)
    {
        try
        {
            std::regex words(regex);

            std::map<std::string, uint32_t> wordlist;
            // Word count
            for (std::sregex_iterator i = std::sregex_iterator(buffer.begin(), buffer.end(), words);
                 i != std::sregex_iterator();
                 ++i)
            {
                std::smatch sm = *i;
                if (sm.empty())
                {
                    spdlog::info("No match found in {}", __PRETTY_FUNCTION__);
                    return {};
                }

                auto searchFound = wordlist.find(sm.str());
                if (searchFound != wordlist.end())
                {
                    // word found again, increment the count
                    wordlist[sm.str()] = searchFound->second + 1;
                    continue;
                }
                wordlist[sm.str()] = 1;
            }

            std::set<std::pair<uint32_t, std::string>> interchanged;
            // interchnage the pair from <std::string, uint32_t> to <uint32_t, std::string>
            for (auto const &item : wordlist)
            {
                interchanged.emplace(item.second, item.first);
            }

            std::vector<std::pair<std::string, uint32_t>> wordCount;
            uint32_t count = 0;
            for (auto it = interchanged.rbegin(); it != interchanged.rend(); ++it)
            {
                wordCount.emplace_back(std::make_pair(it->second, it->first));
                if (++count == 10)
                    break;
            }
            return wordCount;
        }
        catch (const std::exception &e)
        {
            spdlog::error("Excption caught in {} {}", __PRETTY_FUNCTION__, e.what());
            return {};
        }
    }

    std::vector<std::pair<std::string, uint32_t>> TextParser::computeSmileys(const std::string &buffer, const std::string& regex)
    {
        try
        {
            std::regex smiley(regex);

            std::smatch sm;
            int index = 0;

            std::vector<std::pair<std::string, uint32_t>> smileyIndexList;
            auto textBlock = buffer;
            while (std::regex_search(textBlock, sm, smiley))
            {
                if (sm.empty())
                {
                    spdlog::info("No match found in {}", __PRETTY_FUNCTION__);
                    return {};
                }

                index = index + sm.position(0);
                if ((sm.str(0)).rfind(":", 0) == 0)
                {
                    smileyIndexList.emplace_back(std::make_pair(sm.str(0), index));
                }
                textBlock = sm.suffix().str();
            }
            return smileyIndexList;
        }
        catch (const std::exception &e)
        {
            spdlog::error("Excption caught in {} {}", __PRETTY_FUNCTION__, e.what());
            return {};
        }
    }
} // namespace util
