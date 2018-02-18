#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SnakeBody.h"
#include <deque>
#include <SDL_keycode.h>

namespace Snake
{
    DECLARE_SMART(SnakeBody, spSnakeBody);

    class SnakeNervousSystem
    {
    public:
        SnakeNervousSystem (unit_size_t snakeBodySize);
//        ~SnakeNervousSystem () {};

        void check ();
        void start ();

    protected:
        void moveUp (unsigned long index = 0);
        void moveLeft (unsigned long index = 0);
        void moveDown (unsigned long index = 0);
        void moveRight (unsigned long index = 0);

        void addBody (spSnakeBody snakeBody);

        unit_size_t bodySize;

    private:
        std::deque <spSnakeBody> bodies;
        char currentMoveDirection;

        const timeMS DELAY = 100;

        void pressArrow (Event* ev);
        void throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from = 0);
        void addWillMoveForAllBodies (char direction, unsigned long bodyIndex);

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();

        void move (unsigned long index, char direction);
    };
}


#endif //SNAKE_SNAKE_H
