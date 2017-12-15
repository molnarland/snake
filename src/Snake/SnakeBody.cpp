#include <core/oxygine.h>
#include "SnakeBody.h"

namespace Game
{
    SnakeBody::SnakeBody (signed short startPositionX, signed short startPositionY)
    {
        _positionX = startPositionX * STEP_X;
        _positionY = startPositionY * STEP_Y;

        setSize((float) WIDTH, (float) HEIGHT);
        setColor(0, 0, 0, 255);
        setPosition((float) _positionX, (float) _positionY);
        attachTo(getStage());
    }

    void SnakeBody::addWillMove (unsigned short steps, char direction)
    {
        willMoves.push_back({steps, direction});
    }

    std::deque<will_move_t> SnakeBody::getWillMoves ()
    {
        return willMoves;
    }

    void SnakeBody::removeFirstMove ()
    {
        willMoves.pop_front();
    }

    bool SnakeBody::getCanMove ()
    {
        return _canMove;
    }

    void SnakeBody::setCanMove (bool canMove)
    {
        _canMove = canMove;
    }

    void SnakeBody::goUp (Event *)
    {
        if (_canMove)
        {
            _positionY -= STEP_Y;
            directon = Direction::UP;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goLeft (Event *)
    {
        if (_canMove)
        {
            _positionX -= STEP_X;
            directon = Direction::LEFT;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::goDown (Event *)
    {
        if (_canMove)
        {
            _positionY += STEP_Y;
            directon = Direction::DOWN;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goRight (Event *)
    {
        if (_canMove)
        {
            _positionX += STEP_X;
            directon = Direction::RIGHT;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        addTween(ColorRectSprite::TweenPosition((int) _positionX, (int) _positionY), 1);
    }

    position_t SnakeBody::getPosition ()
    {
        return {_positionX, _positionY};
    }
}