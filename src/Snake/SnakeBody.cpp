#include <Stage.h>
#include "SnakeBody.h"

namespace Kigyo
{
    SnakeBody::SnakeBody ()
    {
        positionX = 100;
        positionY = 100;

        setSize(WIDTH, HEIGHT);
        setColor(0, 0, 0, 255);
        setPosition(positionX, positionY);
        attachTo(oxygine::getStage());
    }

    void SnakeBody::goUp (Event *)
    {
        positionY -= STEP_Y;

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goRight (Event *)
    {
        positionX -= STEP_X;

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::goDown (Event *)
    {
        positionY += STEP_Y;

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goLeft (Event *)
    {
        positionX += STEP_X;

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        addTween(ColorRectSprite::TweenPosition(positionX, positionY),
                 TweenOptions(1).delay(delay).doneCallback(callback));
    }
}