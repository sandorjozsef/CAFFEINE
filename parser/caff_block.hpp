#ifndef CAFF_BLOCK_HPP
#define CAFF_BLOCK_HPP

#include "parsable.hpp"
#include <memory>

namespace parsing
{
    class CAFF_BLOCK: public Parsable
    {
        public:
            int ID;
            int length;
            std::shared_ptr<Parsable> data;
            void parse(std::vector<unsigned char>& bytes);
    };
}

#endif
