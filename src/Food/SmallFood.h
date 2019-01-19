#ifndef SNAKE_SMALLFOOD_H
#define SNAKE_SMALLFOOD_H

#include <ox/ColorRectSprite.hpp>
#include "IFood.h"
#include "../Objects/Size.h"

using namespace oxygine;

namespace Food
{
    class SmallFood: public IFood, public ColorRectSprite
    {
    public:
        SmallFood (position_t position, unit_size_t size);

        void make ();
        void eat ();

    protected:
        const unsigned int point = 10;
    };
}


#endif //SNAKE_SMALLFOOD_H
