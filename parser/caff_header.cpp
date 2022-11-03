#include "caff_header.hpp"

#include <vector>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace parsing;
using namespace std;

vector<unsigned char> CAFF_HEADER::parse(vector<unsigned char> bytes)
{

    //Verify size of the header it must be 20
    if(bytes.size() != 20){
        throw invalid_argument("Size is not equal to 20, it can not be a valid CAFF HEADER");
    }

    //Get magic vaule
    magic.append(bytes.begin(), bytes.begin() + 4);

    //Verify magic value
    if(magic.compare("CAFF") != 0){
        throw invalid_argument("CAFF HEADER magic does not correspond" + magic);
    }

    //Remove magic value from byte array
    bytes.erase(bytes.begin(), bytes.begin() + 4);

    //tmp to store bytes
    unsigned char tmp[8];
    std::copy(bytes.begin(), bytes.begin() + 8, tmp);

    //Make 8 byte long integer to a real integer
    std::memcpy(&header_size, tmp, sizeof(int));

    cout << "... place of parsing CAFF_HEADER ..." << endl;
    std::cout << "Header size" << header_size << std::endl;

    //Delete sequence
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    //Copy number of animations into tmp
    std::copy(bytes.begin(), bytes.begin() + 8, tmp);

    //Make 8 byte long integer to a real integer
    std::memcpy(&num_anim, tmp, sizeof(int));

    std::cout << "Number of animations" << num_anim << std::endl;

    //Delete the last sequence
    bytes.erase(bytes.begin(), bytes.begin() + 8);
    
    return bytes;
}