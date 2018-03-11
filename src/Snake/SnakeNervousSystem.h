#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SnakeBody.h"
#include <deque>
#include <SDL_keycode.h>

using namespace std;

namespace Snake
{
    DECLARE_SMART(SnakeBody, spSnakeBody);

    class SnakeNervousSystem
    {
    public:
        SnakeNervousSystem (unit_size_t snakeBodySize);

        void check ();
        void start ();
        void grow ();

        size_t getBodyLength ();

        spSnakeBody getOneBody (unsigned long index);
        spSnakeBody getHead ();
        spSnakeBody getTail ();

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
        bool canMove = true;

        void pressArrow (Event* ev);
        void throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from = 0);
        void addWillMoveForAllBodies (char direction, unsigned long bodyIndex);

        void growSetBody ();
        void growSetWillMoves ();
        void growSetCurrentMove ();

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();

        void goSomewhere (char direction, unsigned long bodyIndex);

        void move (unsigned long index, char direction);

        void checkDirection (char direction, function <void ()> up, function <void ()> left,
                             function <void ()> down, function <void ()> right);
    };
}


#endif //SNAKE_SNAKE_H
