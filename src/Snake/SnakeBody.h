#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include <Stage.h>
#include <ColorRectSprite.h>
#include <deque>
#include "../Objects/Direction.h"
#include "../Objects/Position.h"
#include "../Objects/WillMove.h"


using namespace oxygine;
using namespace GameObject;

namespace Game
{
    class SnakeBody : public ColorRectSprite
    {
    public:
        SnakeBody (signed short startPositionX, signed short startPositionY, timeMS delay);

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

        void setDirection (Direction direction);

        void setCanMove (bool canMove);
        bool getCanMove ();

        void addWillMove (unsigned short steps, char direction);
        std::deque<will_move_t> getWillMoves ();
        void removeFirstMove ();

        std::deque<will_move_t> willMoves;

        char directon;

        position_t getPosition ();

    private:
        double _positionX;
        double _positionY;

        const double WIDTH = getStage()->getWidth() / 50;
        const double HEIGHT = getStage()->getHeight() / (50 / (getStage()->getWidth() / getStage()->getHeight()));

        const double STEP_X = WIDTH;
        const double STEP_Y = HEIGHT;

        bool _canMove = true;

        timeMS _delay;

        void go (const EventCallback &callback);
    };
};


#endif //SNAKE_SNAKEBODY_H
