#include "parser.hpp"
#include "caff_block.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;


CAFF Parser::process(vector<char> bytes)
{
    cout << "\nThe content of the file: \n\n";

    CAFF_BLOCK block;
    vector<char> unprocessed_bytes = block.parse(bytes);
    

    CAFF caff;
    return caff;
}
