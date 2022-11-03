#ifndef CAFF_HEADER_HPP
#define CAFF_HEADER_HPP

#include "parsable.hpp"

#include <string>

namespace parsing
{
    class CAFF_HEADER: public Parsable
    {
        public:
            std::string get_magic();
            int get_header_size();
            int get_num_anim();
            std::vector<unsigned char> parse(std::vector<unsigned char> bytes);

        private:
            std::string magic;
            int header_size;
            int num_anim;
            void check_caff_magic(std::vector<unsigned char> characters);
            void check_header_length(std::vector<unsigned char> header_size_bytes);
            void set_num_anim_from_bytes(std::vector<unsigned char> bytes);
    };
}

#endif