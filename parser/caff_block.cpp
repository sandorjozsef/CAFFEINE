#include "caff_block.hpp"
#include "caff_header.hpp"
#include "caff_credits.hpp"
#include "caff_animation.hpp"

#include <vector>
#include <iostream>
#include <cmath>

using namespace parsing;
using namespace std;

vector<unsigned char> CAFF_BLOCK::parse(vector<unsigned char> bytes)
{

    if (bytes.size() < 9) {
        throw invalid_argument("CAFF_BLOCK too short (< 9)");
    }

    ID = bytes[0];
    if (ID < 1 || ID > 3){
        throw invalid_argument("Invalid ID: " + to_string(ID));
    }

    length = 0;
    vector<unsigned char> length_bytes(bytes.begin() + 1, bytes.begin() + 9);
    for (int i = 0; i < 8; i++) {
        length += (length_bytes[i] * pow(256, i)); // conversion to decimal
    }

    bytes.erase(bytes.begin(), bytes.begin() + 9); // delete first 1 + 8 elements from bytes

    if (static_cast<int>(bytes.size()) < length) {
        throw invalid_argument("CAFF_BLOCK too short (actual size < length)");
    }

    vector<unsigned char> data_bytes(bytes.begin(), bytes.begin() + length); // copy unprocessed data for further parsing

    switch (ID)
    {
        case 1:
            data = new CAFF_HEADER();
            break;

        case 2:
            data = new CAFF_CREDITS();
            break;

        case 3:
            data = new CAFF_ANIMATION();
            break;
    }

    vector<unsigned char> unprocessed = data->parse(data_bytes); // if everything is fine: unprocessed vector is empty


    bytes.erase(bytes.begin(), bytes.begin() + length); // delete processed data from bytes

    return bytes;
}