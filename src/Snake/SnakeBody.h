#include <ColorRectSprite.h>

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

using namespace oxygine;

namespace Snake
{
    class SnakeBody : public ColorRectSprite
    {
    public:
        long positionX;
        long positionY;

        SnakeBody ();

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

    private:
        const signed char WIDTH = 50;
        const signed char HEIGHT = 50;

        const signed char SPEED_X = WIDTH;
        const signed char SPEED_Y = HEIGHT;

        const signed char delay = 100;

        void go (const EventCallback &callback);
        void pressArrow (Event *ev);
    };
}


#endif //SNAKE_SNAKEBODY_H
