#ifndef CAFF_CREDITS_HPP
#define CAFF_CREDITS_HPP

#include "parsable.hpp"

#include <string>

namespace parsing
{
    class CAFF_CREDITS: public Parsable
    {
        public:
            int YY, M, D, h, m;
            int creator_len;
            std::string creator;
            std::vector<unsigned char> parse(std::vector<unsigned char> bytes);
    };
}

#endif