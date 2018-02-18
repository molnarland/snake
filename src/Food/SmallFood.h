#ifndef SNAKE_SMALLFOOD_H
#define SNAKE_SMALLFOOD_H

#include <ColorRectSprite.h>
#include "IFood.h"

using namespace oxygine;

namespace Food
{
    class SmallFood: public IFood, public ColorRectSprite
    {
    public:
        SmallFood (position_t position);

        void make ();
        void eat ();

    protected:
        const unsigned int point = 10;
    };
}


#endif //SNAKE_SMALLFOOD_H
