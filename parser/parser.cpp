#include "parser.hpp"
#include "caff_block.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;


CAFF Parser::process(vector<unsigned char> bytes)
{
    cout << "\nParsing the file: \n";
    
    CAFF caff;

    while( bytes.size() > 0 ){

        CAFF_BLOCK block;
        block.parse(bytes);
        caff.blocks.push_back(block);
    }
    
    return caff;
}
