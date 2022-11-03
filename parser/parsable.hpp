#ifndef PARSABLE_HPP
#define PARSABLE_HPP

#include <vector>

namespace parsing{

    class Parsable
    {
        public:
            virtual std::vector<unsigned char> parse(std::vector<unsigned char> bytes) = 0;
    };

}

#endif