#include "ciff.hpp"

#include "EasyBMP.hpp"
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace parsing;
using namespace std;

void CIFF::parse(vector<unsigned char>& bytes)
{
    cout << "\t\tCIFF parsing ..." << endl;

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

        if (end_line_it == bytes.begin() + caption_and_tags_length)
        {
            throw invalid_argument("CIFF no end line character found for caption!");
        }
        caption = string(bytes.begin(), end_line_it);
        bytes.erase(bytes.begin(), end_line_it + 1);

        int tags_length = caption_and_tags_length - caption.length() - 1;
        if (tags_length == 0)
        {
            tags = vector<string>(0);
        }
        else
        {
            if(bytes[tags_length-1] != '\0')
            {
                throw invalid_argument("CIFF tag ending is not correct");
            }
            for(;tags_length > 0;)
            {
                auto tag_end_it =
                        find(bytes.begin(), bytes.begin() + (size_t)tags_length, '\0');

                if(tag_end_it == bytes.begin() + (size_t)tags_length)
                {
                    throw invalid_argument("CIFF tags not provided correctly");
                }
                string newTag = string(bytes.begin(), tag_end_it);
                tags.push_back(newTag);
                bytes.erase(bytes.begin(), bytes.begin() + newTag.length() + 1);
                tags_length -= (newTag.length() + 1);
            }
        }
    }

    if (bytes.size() != (size_t)content_size)
    {
        throw invalid_argument("CIFF content invalid size!");
    }

    pixels = vector<unsigned char>(bytes);
    bytes.erase(bytes.begin(), bytes.end());

    cout << "\t\tMagic: " << magic << endl;
    cout << "\t\tHeader size: " << header_size << endl;
    cout << "\t\tContent size: "<< content_size << endl;
    cout << "\t\tWidth: " << width << endl;
    cout << "\t\tHeight: " << height << endl;
    cout << "\t\tCaption: " << caption << endl;
    cout << "\t\tTags: ";
    for (string tag : tags){
        cout << tag << "; ";
    }
    cout << endl;

}

void CIFF::save_as_bmp(string file_name)
{
    EasyBMP::Image img(width, height, file_name);

    int offset = 0;
    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            EasyBMP::RGBColor color(pixels[offset], pixels[offset + 1], pixels[offset + 2]);
            offset += 3;
            img.SetPixel(y, x, color);
        }
    }
    img.Write();
}
