#ifndef PARSABLE_HPP
#define PARSABLE_HPP

#include <vector>

namespace parsing{

    class Parsable
    {
        public:
            // this method parses the parameter vector
            // it returns the unprocessed (remaining) part of the parameter vector (returns an empty vector if all of the parameter vector was parsed)
            // if something goes wrong, throws exception
            virtual std::vector<unsigned char> parse(std::vector<unsigned char> bytes) = 0;
    };

}

#endif