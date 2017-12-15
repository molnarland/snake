#ifndef SNAKE_WILLMOVE_H
#define SNAKE_WILLMOVE_H

#include "Direction.h"

namespace GameObject
{
    struct will_move_t
    {
        unsigned short steps;
        char directon;
    };
};

#endif //SNAKE_WILLMOVE_H
