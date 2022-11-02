#pragma once

#include <vector>

namespace parsing{

    class Parsable
    {
        public:
            virtual std::vector<char> parse(std::vector<char> bytes) = 0;
    };

}