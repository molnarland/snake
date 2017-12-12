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
        Snake(bool *canGo);

        void moveLeft ();
        void moveUp ();
        void moveDown ();
        void moveRight ();

        bool *_canGo;
    private:
//        friend class SnakeBody;

        std::deque<spSnakeBody> bodies;
        char currentMoveDirection;

        const timeMS DELAY = 100;



        void pressArrow (Event *ev);

        bool canMoveUp ();
        bool canMoveLeft ();
        bool canMoveDown ();
        bool canMoveRight ();
    };
}


#endif //SNAKE_SNAKE_H
