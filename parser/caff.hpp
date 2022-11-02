#pragma once

#include <vector>

#include "caff_block.hpp"

namespace parsing{

    class CAFF
    {
        public:
            std::vector<CAFF_BLOCK> blocks;
    };

}