#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SnakeBody.h"
#include <deque>
#include <SDL_keycode.h>

namespace Game
{
    DECLARE_SMART(SnakeBody, spSnakeBody);

    class Snake
    {
    public:
        Snake ();

    protected:
        void moveUp (signed long index = 1);
        void moveLeft (signed long index = 1);
        void moveDown (signed long index = 1);

        void moveRight (signed long index = 1);
    private:
//        friend class SnakeBody;

        std::deque <spSnakeBody> bodies;
        char currentMoveDirection;

        const timeMS DELAY = 100;

        void pressArrow (Event* ev);
        void throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from = 0);

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();

        void start ();
    };
}


#endif //SNAKE_SNAKE_H
