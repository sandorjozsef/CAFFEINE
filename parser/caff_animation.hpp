#ifndef CAFF_ANIMATION_HPP
#define CAFF_ANIMATION_HPP

#include "parsable.hpp"

namespace parsing
{
    class CAFF_ANIMATION: public Parsable
    {
        public:
            int duration;
            //TODO: CIFF
            std::vector<unsigned char> parse(std::vector<unsigned char> bytes);
    };
}

#endif