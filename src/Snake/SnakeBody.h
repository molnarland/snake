#include <ColorRectSprite.h>

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

using namespace oxygine;

namespace Kigyo
{
    class SnakeBody : public ColorRectSprite
    {
    public:
        long positionX;
        long positionY;

//        time_t startTime;

        SnakeBody ();

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

    private:
        const signed char WIDTH = 50;
        const signed char HEIGHT = 50;

        const signed char STEP_X = WIDTH;
        const signed char STEP_Y = HEIGHT;

        const signed char delay = 50;

        void go (const EventCallback &callback);
    };
};


#endif //SNAKE_SNAKEBODY_H
