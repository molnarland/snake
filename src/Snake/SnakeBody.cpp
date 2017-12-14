#include <core/oxygine.h>
#include "SnakeBody.h"

namespace Game
{
    SnakeBody::SnakeBody (signed short startPositionX, signed short startPositionY, timeMS delay)
    {
        _positionX = startPositionX * STEP_X;
        _positionY = startPositionY * STEP_Y;
        _delay = delay;

        setSize((float) WIDTH, (float) HEIGHT);
        setColor(0, 0, 0, 255);
        setPosition((float) _positionX, (float) _positionY);
        attachTo(getStage());
    }

    void SnakeBody::addWillMove (unsigned short steps, char direction)
    {
        _willMoves.push_back({steps, direction});
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
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        addTween(ColorRectSprite::TweenPosition((int) _positionX, (int) _positionY),
                 TweenOptions(1)/*.delay(_delay)*/.doneCallback(callback));


        unsigned long willMoveLength = _willMoves.size();

        for (unsigned long index = 0; index < willMoveLength; index++) {
            _willMoves[index].steps--;
        }

        if(_willMoves[0].steps == 0)
        {
            setCanMove(false);
            if (_willMoves[0].directon == Direction::UP)
            {
                goUp(nullptr);
            }
        }
    }

    position_t SnakeBody::getPosition ()
    {
        return {_positionX, _positionY};
    }
}