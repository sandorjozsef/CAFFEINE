#include "caff_animation.hpp"

#include <vector>
#include <iostream>

using namespace parsing;
using namespace std;

vector<unsigned char> CAFF_ANIMATION::parse(vector<unsigned char> bytes)
{
    cout << "\tCAFF ANIMATION parsing ..." << endl;

    if (bytes.size() < 8)
    {
        throw invalid_argument("CAFF_ANIMATION is too short!");
    }

    duration = 0;
    for (int i = 0; i < 8; ++i)
    {
        duration += (bytes[i] << (i * 8));
    }
    bytes.erase(bytes.begin(), bytes.begin() + 8);

    cout << "\tDuration: " << duration << endl;

    if (bytes.size() <= 0)
    {
        throw invalid_argument("CAFF_ANIMATION no CIFF provided!");
    }

    ciff = CIFF();

    bytes = ciff.parse(bytes);

    return bytes;
}