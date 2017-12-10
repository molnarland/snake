#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SnakeBody.h"
#include <deque>
#include <SDL_keycode.h>

namespace Kigyo
{
    DECLARE_SMART(SnakeBody, spSnakeBody);

    class Snake
    {
    public:
        Snake();

    private:
//        friend class SnakeBody;

        const char MOVE_UP = 'U';
        const char MOVE_LEFT = 'L';
        const char MOVE_DOWN = 'D';
        const char MOVE_RIGHT = 'R';

        std::deque<spSnakeBody> bodies;
        char currentMoveDirection;


        void moveUp ();
        void moveLeft ();
        void moveDown ();
        void moveRight ();
        void pressArrow (Event *ev);

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();
    };
}


#endif //SNAKE_SNAKE_H
