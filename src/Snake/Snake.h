#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include "SnakeBody.h"
#include <deque>

namespace Kigyo
{
    DECLARE_SMART(SnakeBody, spSnakeBody);

    class Snake
    {
    public:
        Snake();

    protected:
        friend class SnakeBody;

    private:
        std::deque<spSnakeBody> bodies;

        void pressArrow (Event *ev);
    };
}


#endif //SNAKE_SNAKE_H
