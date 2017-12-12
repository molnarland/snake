#include <core/oxygine.h>
#include "SnakeBody.h"
#include "Directions.h"

namespace Kigyo
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


    void SnakeBody::goUp (Event *)
    {
        if (!dontMove)
        {
            printf("moveUp: ");
            _positionY -= STEP_Y;
        }
        else
        {
            dontMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goLeft (Event *)
    {
        if (!dontMove)
        {
            printf("moveLeft: ");
            _positionX -= STEP_X;
        }
        else
        {
            dontMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::goDown (Event *)
    {
        if (!dontMove)
        {
            printf("moveDown: ");
            _positionY += STEP_Y;
        }
        else
        {
            dontMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goRight (Event *)
    {
        if (!dontMove)
        {
            printf("moveRight: ");
            _positionX += STEP_X;
        }
        else
        {
            dontMove = false;
        }

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        printf("%d - %d\n", (int) _positionX, (int) _positionY);
        addTween(ColorRectSprite::TweenPosition((int) _positionX, (int) _positionY),
                 TweenOptions(1)/*.delay(_delay)*/.doneCallback(callback));
    }
}