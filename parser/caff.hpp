#ifndef CAFF_HPP
#define CAFF_HPP

#include <vector>

#include "caff_block.hpp"

namespace parsing{

    class CAFF
    {
        public:
            std::vector<CAFF_BLOCK> blocks;
            void preview();
    };

}

#endif