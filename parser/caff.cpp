#include "caff.hpp"
#include "caff_animation.hpp"

using namespace parsing;
using namespace std;

void CAFF::preview()
{
    int seq_nr = 1;
    for (auto block : blocks)
    {
        if (block.ID == 3)
        {
            CAFF_ANIMATION* caff_animation = dynamic_cast<CAFF_ANIMATION*>(block.data);
            caff_animation->ciff.save_as_bmp(to_string(seq_nr) + ".bmp");
            seq_nr++;
        }
    }

}