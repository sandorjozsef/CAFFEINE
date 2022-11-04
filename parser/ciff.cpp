#include "ciff.hpp"

#include<iterator>
#include <vector>
#include <iostream>
#include <cmath>

using namespace parsing;
using namespace std;

vector<unsigned char> CIFF::parse(vector<unsigned char> bytes)
{
    cout << "... place of parsing CIFF ..." << endl;

    if (bytes.size() < 36)
    {
        throw invalid_argument("CIFF is too short!");
    }

    magic = string(bytes.begin(), bytes.begin() + 4);
    if (magic != "CIFF")
    {
        throw invalid_argument("CIFF invalid magic!");
    }
    bytes.erase(bytes.begin(), bytes.begin() + 4);

    header_size = 0;
    for (int i = 0; i < 8; ++i)
    {
        header_size += (bytes[i] << (i * 8));
    }
    if ((size_t)header_size > bytes.size() + 4)
    {
        throw invalid_argument("CIFF invalid header size!");
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    content_size = 0;
    for (int i = 0; i < 8; ++i)
    {
        content_size += (bytes[i] << (i * 8));
    }
    if ((size_t)(header_size + content_size) != bytes.size() + 12)
    {
        throw invalid_argument("CIFF invalid size!");
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    width = 0;
    for (int i = 0; i < 8; ++i)
    {
        width += (bytes[i] << (i * 8));
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    height = 0;
    for (int i = 0; i < 8; ++i)
    {
        height += (bytes[i] << (i * 8));
    }
    if (content_size != (width * height * 3))
    {
        throw invalid_argument("CIFF invalid content size!");
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    int caption_and_tags_length = header_size - 36;
    if (caption_and_tags_length == 0)
    {
        caption = "";
        tags = vector<string>(0);
    }
    else
    {
        auto end_line_it =
                find(bytes.begin(), bytes.begin() + (size_t)caption_and_tags_length, '\n');

        if (end_line_it != bytes.begin() + caption_and_tags_length)
        {
            caption = string(bytes.begin(), end_line_it);
            bytes.erase(bytes.begin(), end_line_it + 1);
        }
        else
        {
            throw invalid_argument("CIFF no end line character found for caption!");
        }

        int tags_length = caption_and_tags_length - caption.length() - 1;
        if (tags_length == 0)
        {
            tags = vector<string>(0);
        }
        else
        {
            int i = 0;
            while (false) {}
        }
    }

    cout << header_size << endl;
    cout << content_size << endl;
    cout << width << endl;
    cout << height << endl;

    return bytes;
}
