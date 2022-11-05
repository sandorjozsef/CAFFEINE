#ifndef CAFF_ANIMATION_HPP
#define CAFF_ANIMATION_HPP

#include "parsable.hpp"
#include "ciff.hpp"

namespace parsing
{
    class CAFF_ANIMATION: public Parsable
    {
        public:
            int duration;
            CIFF ciff;
            void parse(std::vector<unsigned char>& bytes);
    };
}

#endif