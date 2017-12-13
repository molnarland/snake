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

    void SnakeBody::setDirection (Direction direction)
    {
        _directon = direction;
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
            printf("moveUp: ");
            _positionY -= STEP_Y;
        }
        else
        {
            _canMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goLeft (Event *)
    {
        if (_canMove)
        {
            printf("moveLeft: ");
            _positionX -= STEP_X;
        }
        else
        {
            _canMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::goDown (Event *)
    {
        if (_canMove)
        {
            printf("moveDown: ");
            _positionY += STEP_Y;
        }
        else
        {
            _canMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goRight (Event *)
    {
        if (_canMove)
        {
            printf("moveRight: ");
            _positionX += STEP_X;
        }
        else
        {
            _canMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        printf("%d - %d\n", (int) _positionX, (int) _positionY);
        addTween(ColorRectSprite::TweenPosition((int) _positionX, (int) _positionY),
                 TweenOptions(1)/*.delay(_delay)*/.doneCallback(callback));
    }

    position_t SnakeBody::getPosition ()
    {
        return {_positionX, _positionY};
    }
}