#include "caff_header.hpp"

#include <vector>
#include <iostream>
#include <cmath>

using namespace parsing;
using namespace std;

vector<unsigned char> CAFF_HEADER::parse(vector<unsigned char> bytes)
{
    cout << "Parsing CAFF_HEADER ..." << endl;

    if (bytes.size() != 20)
    {
        throw invalid_argument("CAFF_HEADER too short (actual size < 20)");
    }

    vector<unsigned char> caff_magic_characters(bytes.begin(), bytes.begin() + 4);
    check_caff_magic(caff_magic_characters);

    vector<unsigned char> header_size_bytes(bytes.begin() + 4, bytes.begin() + 12);
    check_header_length(header_size_bytes);

    vector<unsigned char> num_anim_bytes(bytes.begin() + 12, bytes.begin() + 20);
    set_num_anim_from_bytes(num_anim_bytes);

    bytes.erase(bytes.begin(), bytes.begin() + 20);
    cout << "Parse of CAFF_HEADER was successful!" << endl << endl;
    return bytes;
}

void CAFF_HEADER::check_caff_magic(vector<unsigned char> characters)
{
    string caff_magic = "CAFF";
    for (int i = 0; i < 4; ++i)
    {
        if (characters[i] != caff_magic[i])
        {
            throw invalid_argument("CAFF_HEADER magic is invalid!");
        }
    }
    magic = "CAFF";
    cout << "CAFF_HEADER magic is valid!" << endl;
}

void CAFF_HEADER::check_header_length(vector<unsigned char> header_size_bytes)
{
    int size = 0;
    for (int i = 0; i < 8; i++) {
        size += (header_size_bytes[i] * pow(256, i));
    }
    if (size != 20)
    {
        throw invalid_argument("CAFF_HEADER length is invalid!");
    }
    header_size = size;
    cout << "CAFF_HEADER size is valid!" << endl;
}

void CAFF_HEADER::set_num_anim_from_bytes(vector<unsigned char> bytes)
{
    num_anim = 0;
    for (int i = 0; i < 8; ++i)
    {
        num_anim += (bytes[i] * pow(256, i));
    }

    cout << "CAFF_HEADER number of animated CIFFs " << get_num_anim() << "!" << endl;
}

string CAFF_HEADER::get_magic()
{
    return magic;
}

int CAFF_HEADER::get_header_size()
{
    return header_size;
}

int CAFF_HEADER::get_num_anim()
{
    return num_anim;
}
