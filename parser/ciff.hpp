#ifndef CIFF_HPP
#define CIFF_HPP

#include "parsable.hpp"

#include <string>
#include <vector>

namespace parsing
{
    class CIFF: public Parsable
    {
        public:
            std::string magic;
            int header_size;
            int content_size;
            int width;
            int height;
            std::string caption;
            std::vector<std::string> tags;
            std::vector<unsigned char> pixels;
            void parse(std::vector<unsigned char>& bytes);
            void save_as_bmp(std::string file_name);
    };
}

#endif
