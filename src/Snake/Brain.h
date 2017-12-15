#ifndef SNAKE_BRAIN_H
#define SNAKE_BRAIN_H

#include "Snake.h"

namespace Game
{
    class Brain : public Snake
    {
    public:
        Brain();

        void start ();

        void check ();
    };
};


#endif //SNAKE_BRAIN_H
