#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H

#include <Stage.h>
#include <ColorRectSprite.h>
#include <deque>
#include "../Objects/Direction.h"
#include "../Objects/Position.h"
#include "../Objects/WillMove.h"
#include "../Objects/Size.h"
#include "../Objects/StepSize.h"
//#include "../Objects/StepSize.h"

using namespace oxygine;

namespace Snake
{
    class SnakeBody : public ColorRectSprite
    {
    public:
        SnakeBody (GameObject::position_t startPosition, unit_size_t snakeBodySize);

        void goUp (Event*);
        void goRight (Event*);
        void goDown (Event*);
        void goLeft (Event*);

        void setDirection (GameObject::Direction direction);

        void setCanMove (bool canMove);
        bool getCanMove ();

        void addWillMove (unsigned long steps, char direction);
        std::deque<GameObject::will_move_t> getWillMoves ();
        void removeFirstMove ();

        std::deque<GameObject::will_move_t> willMoves;

        char directon;

        GameObject::position_t getPosition ();

    private:
        double _positionX;
        double _positionY;

        bool _canMove = true;

        unit_size_t size;
        step_size_t stepSize;

        void go (const EventCallback &callback);
    };
};


#endif //SNAKE_SNAKEBODY_H
