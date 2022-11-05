#ifndef CAFF_BLOCK_HPP
#define CAFF_BLOCK_HPP

#include "parsable.hpp"

namespace parsing
{
    class CAFF_BLOCK: public Parsable
    {
        public:
            int ID;
            int length;
            Parsable* data;
            void parse(std::vector<unsigned char>& bytes);
    };
}

#endif
