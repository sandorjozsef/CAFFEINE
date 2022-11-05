#include "parser.hpp"
#include "caff_block.hpp"
#include "caff_header.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;


CAFF Parser::process(vector<unsigned char>& bytes)
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

// checking further constraints related to semantics
void Parser::post_process(CAFF& caff)
{
    auto blocks = caff.blocks;

    if (blocks.size() < 3)
    {
        throw invalid_argument("CAFF file does not contain enough blocks (<3)");
    }

    if (blocks[0].ID != 1)
    {
        throw invalid_argument("First block is not HEADER BLOCK");
    }

    if (blocks[1].ID != 2)
    {
        throw invalid_argument("Second block is not CREDITS BLOCK");
    }

    for (int i = 2; i < blocks.size(); i++)
    if (blocks[i].ID != 3)
    {
        throw invalid_argument("ANIMATION BLOCK was expected, it caught something else.");
    }

    int num_anim = 0;
    for (auto block : blocks)
    {
        if (block.ID == 3)
        {
            num_anim++;
        }
    }

    auto header_block = dynamic_cast<CAFF_HEADER*>(blocks[0].data);
    if (num_anim != header_block->num_anim)
    {
        throw invalid_argument("The actual nr. of animation blocks does not correspond with the nr. that was defined in header");
    }

}
