#pragma once
#include <list>
#include <string>
#include <regex>
#include <iostream>

using StrList = std::list<std::string>;
using CoordsPair = std::pair<int, int>;

namespace game
{
    namespace input
    {
        namespace commands
        {
            const std::string END_GAME = "q";
            const std::string DEPLOY_SHIP = "ds";
            const std::string FINISH_DEVELOPMENT = "fd";
            const std::string BOARD_RESIZE = "r";
            const std::string TAKE_SHOT = "s";
        }
        namespace patterns
        {
            const std::regex BOARD_RESIZE_GENERAL("(10|[0-9]), (10|[0-9])");
        }
        namespace functions
        {
            inline int CTOI(const char c)
            {
                std::string str{c};
                return atoi(str.c_str());
            }

            inline int GET_CHAR_POS(const std::string& str, char c)
            {
                for (unsigned int i = 0; i < str.size(); ++i)
                {
                    if (str[i] == c)
                    {
                        return i;
                    }
                }
                return -1;
            }

            inline const StrList SPLIT_STR_AT_POS(const unsigned int pos,
                                                  const std::string& str)
            {
                StrList splitList;
                const unsigned int end = str.size() - 1;
                std::string splitted;
                for (unsigned int i = 0; i < str.size(); ++i)
                {
                    if (i != pos)
                    {
                        splitted.push_back(str[i]);
                    }
                    if ((i == pos) || (i == end))
                    {
                        splitList.push_back(splitted);
                        splitted.clear();
                    }
                }
                return splitList;
            }

            inline const StrList SPLIT_STR(std::string str, char c)
            {
                const int pos = GET_CHAR_POS(str, c);
                StrList splitList;
                if (pos != -1)
                {
                    splitList = SPLIT_STR_AT_POS(pos, str);
                }
                return splitList;
            }

            inline const CoordsPair PARSE_COORDS_INPUT(const std::string& input)
            {
                CoordsPair coordsPair;
                const StrList coordStrsList = input::functions::SPLIT_STR(input, ',');

                const std::string firstChunk = coordStrsList.front();
                std::string secondChunk = coordStrsList.back();
                secondChunk.erase(0,1);

                auto assignChunkValue = [](const std::string& chunk)
                {
                    int value = 0;
                    if (chunk.size() > 1)
                    {
                        value = std::stoi(chunk);
                    }
                    else
                    {
                        value = input::functions::CTOI(chunk.front());
                    }
                    return value;
                };

                coordsPair.first = assignChunkValue(firstChunk);
                coordsPair.second = assignChunkValue(secondChunk);

                return coordsPair;
            }

            inline bool INPUT_MATCHES_PATTERN(const std::regex& pattern,
                                              const std::string& input)
            {
                bool result = false;
                if(std::regex_match(input, pattern))
                {
                    result = true;
                }
                return result;
            }
        }
    }
}

class InputObserver
{
public:
    virtual ~InputObserver() {}
    virtual void onInputUpdate(const std::string&) = 0;
};
