#pragma once

#include "parsable.hpp"

namespace parsing
{
    class CAFF_BLOCK: public Parsable
    {
        public:
            int ID;
            int length;
            Parsable* data;
            std::vector<char> parse(std::vector<char> bytes);
    };
}

