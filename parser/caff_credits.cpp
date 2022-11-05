#include "caff_credits.hpp"

#include <vector>
#include <iostream>
#include <cmath>

using namespace parsing;
using namespace std;

void CAFF_CREDITS::parse(vector<unsigned char>& bytes)
{

    cout << "\tCAFF CREDITS parsing ..." << endl;

    if (bytes.size() < 14)
    {
        throw invalid_argument("CAFF_CREDITS is too short!");
    }

    YY = bytes[0] + (bytes[1] << 8);
    M = bytes[2];
    D = bytes[3];
    h = bytes[4];
    m = bytes[5];

    bytes.erase(bytes.begin(), bytes.begin() + 6);

    creator_len = 0;
    for (int i = 0; i < 8; ++i)
    {
        creator_len += (bytes[i] << (i * 8));
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    if (bytes.size() != (size_t)creator_len)
    {
        throw invalid_argument("CAFF_CREDITS invalid creator length!");
    }

    if (creator_len == 0)
    {
        creator = "";
    }
    else
    {
        creator = string(bytes.begin(), bytes.begin() + creator_len);
    }
    bytes.erase(bytes.begin(), bytes.begin() + creator_len);

    if (bytes.size() != 0)
    {
        throw invalid_argument("CAFF_CREDITS invalid creator length!");
    }

    cout << "\tY: " << YY << endl;
    cout << "\tD: " << D << endl;
    cout << "\tM: " << M << endl;
    cout << "\th: " << h << endl;
    cout << "\tm: " << m << endl;
    cout << "\tLength of creator: " << creator_len << endl;
    cout << "\tCreator: " << creator << endl;

}