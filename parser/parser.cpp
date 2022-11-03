#include "parser.hpp"
#include "caff_block.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;


CAFF Parser::process(vector<unsigned char> bytes)
{
    cout << "\nParsing the file: \n\n";
    
    CAFF caff;

    while( bytes.size() > 0 ){

        CAFF_BLOCK block;
        bytes = block.parse(bytes);
        cout << "\tID: " << block.ID << endl;
        cout << "\tlength: " << block.length << endl;
        caff.blocks.push_back(block);
    }
    
    return caff;
}
