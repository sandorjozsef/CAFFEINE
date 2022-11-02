#include "parser.h"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;


void Parser::process(vector<char> bytes)
{
    cout << "\nThe content of the file: \n\n";

    int ID = bytes[0];
    if ( ID >= 1 && ID <= 3){
        cout << "ID = " << ID << endl;
    }
    else{
        throw "Invalid ID";
    }

    // TODO: int is enough for 8 byte integer
    // TODO: checking long enough the bytes vector ??
    int length = 0;
    for (int i = 0; i < 8; i++){
        length += (bytes[i+1] << (i * 8)); // bit shifting
    }
    
    cout << "length = " << length;

    // switch case ID = 1, 2, 3 ...
}
