#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include "caff.hpp"

namespace parsing
{
    class Parser
    {
        public:
            CAFF process(std::vector<unsigned char>& bytes);
            void post_process(CAFF& caff);
    };
}

#endif