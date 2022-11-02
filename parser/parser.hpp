#pragma once

#include <vector>
#include "caff.hpp"

namespace parsing
{
    class Parser
    {
        public:
            CAFF process(std::vector<char> bytes);
    };
}

