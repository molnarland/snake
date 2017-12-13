#ifndef SNAKE_BRAIN_H
#define SNAKE_BRAIN_H

#include "Snake.h"

namespace Game
{
    class Brain : private Snake
    {
    public:
        Brain();

        void check ();
    };
};


#endif //SNAKE_BRAIN_H
