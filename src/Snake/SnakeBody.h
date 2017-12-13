#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include <Stage.h>
#include <ColorRectSprite.h>
#include "../Objects/Directions.h"
#include "../Objects/Position.h"


using namespace oxygine;
using namespace GameObject;

namespace Game
{
    class SnakeBody : public ColorRectSprite
    {
    public:
//        time_t startTime;

        SnakeBody (signed short startPositionX, signed short startPositionY, timeMS delay);

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

        void setDirection (Direction direction);

        void setCanMove (bool canMove);
        bool getCanMove ();

        position_t getPosition ();
    private:
        double _positionX;
        double _positionY;

        const double WIDTH = getStage()->getWidth() / 50;
        const double HEIGHT = getStage()->getHeight() / (50 / (getStage()->getWidth() / getStage()->getHeight()));

        const double STEP_X = WIDTH;
        const double STEP_Y = HEIGHT;

        bool _canMove = true;

        Direction _directon;

        timeMS _delay;

        void go (const EventCallback &callback);
    };
};


#endif //SNAKE_SNAKEBODY_H
