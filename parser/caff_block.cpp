#include "caff_block.hpp"
#include "caff_header.hpp"
#include "caff_credits.hpp"
#include "caff_animation.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;

void CAFF_BLOCK::parse(vector<unsigned char>& bytes)
{

    cout << "\nCAFF BLOCK parsing ..." << endl;

    if (bytes.size() < 9){
        throw invalid_argument("CAFF_BLOCK too short (< 9)");
    }
    
    ID = bytes[0];
    if ( ID < 1 || ID > 3){
        throw invalid_argument("Invalid ID: " + to_string(ID));
    }

    bytes.erase(bytes.begin(), bytes.begin() + 1); // delete first processed element from bytes

    length = 0;
    for (int i = 0; i < 8; i++){
        length += (bytes[i] << (i * 8)); // conversion to decimal
    }
    
    bytes.erase(bytes.begin(), bytes.begin() + 8); // delete first 8 elements from bytes

    if (static_cast<int>(bytes.size()) < length){
        throw invalid_argument("CAFF_BLOCK too short (actual size < length)");
    }

    cout << "ID: " << ID << endl;
    cout << "Length: " << length << endl;

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

    data->parse(data_bytes); // if everything is fine: all data_bytes is processed

    if (data_bytes.size() != 0)
    {
        throw invalid_argument("CAFF data content is too long.");
    }

    bytes.erase(bytes.begin(), bytes.begin() + length); // delete processed data from bytes
    
}