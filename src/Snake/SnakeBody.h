#include <Stage.h>
#include <ColorRectSprite.h>
#include "Directions.h"

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

using namespace oxygine;

namespace Kigyo
{
    class SnakeBody : public ColorRectSprite
    {
    public:
        double _positionX;
        double _positionY;

//        time_t startTime;

        SnakeBody (signed short startPositionX, signed short startPositionY, timeMS delay);

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

        void setDirection (Direction direction);

        bool dontMove = false;

    private:
        const double WIDTH = getStage()->getWidth() / 50;
        const double HEIGHT = getStage()->getHeight() / (50 / (getStage()->getWidth() / getStage()->getHeight()));

        const double STEP_X = WIDTH;
        const double STEP_Y = HEIGHT;

        Direction _directon;

        timeMS _delay;

        void go (const EventCallback &callback);
    };
};


#endif //SNAKE_SNAKEBODY_H
