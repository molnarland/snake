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
        Snake (bool* canGo);

        void check ();

        bool* _canMove;
    private:
//        friend class SnakeBody;

        std::deque <spSnakeBody> bodies;
        char currentMoveDirection;

        const timeMS DELAY = 100;

        void pressArrow (Event* ev);
        void throughAllBody (std::function <void (unsigned long index)> callback);

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();

        void moveUp (unsigned long index = 1);
        void moveLeft (unsigned long index = 1);
        void moveDown (unsigned long index = 1);
        void moveRight (unsigned long index = 1);
        void start ();
    };
}


#endif //SNAKE_SNAKE_H
