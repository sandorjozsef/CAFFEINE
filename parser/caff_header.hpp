#ifndef CAFF_HEADER_HPP
#define CAFF_HEADER_HPP

#include "parsable.hpp"

#include <string>

namespace parsing
{
    class CAFF_HEADER: public Parsable
    {
        public:
            std::string magic;
            int header_size;
            int num_anim;
            void parse(std::vector<unsigned char>& bytes);
    };
}

#endif