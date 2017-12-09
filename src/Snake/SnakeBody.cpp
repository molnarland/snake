#include "oxygine-framework.h"
#include "SnakeBody.h"
#include <string.h>

namespace Snake
{
    SnakeBody::SnakeBody ()
    {
        positionX = 100;
        positionY = 100;

        setSize(WIDTH, HEIGHT);
        setColor(0, 0, 0, 255);
        setPosition(positionX, positionY);
        attachTo(oxygine::getStage());

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &SnakeBody::pressArrow));

        goLeft(NULL);
    }

/*void SnakeBody::goLeft ()
{
    positionX += speedX;

    addTween(ColorRectSprite::TweenPosition(positionX, 100),
             TweenOptions(1).delay(delay).doneCallback(CLOSURE(this, &SnakeBody::goLeft)));
}*/

    void SnakeBody::pressArrow (Event *ev)
    {
        SDL_Event *event = (SDL_Event *) ev->userData;

//    log::messageln((std::string)event->type);

        if (event->type != SDL_KEYDOWN)
        {
            return;
        }

        removeTweens();
        printf("\n");

        switch (event->key.keysym.sym)
        {
            case SDLK_w:
                goUp(NULL);
                break;
            case SDLK_a:
                goRight(NULL);
                break;
            case SDLK_s:
                goDown(NULL);
                break;
            case SDLK_d:
                goLeft(NULL);
                break;
        }

    }

    void SnakeBody::goUp (Event *)
    {
        positionY -= SPEED_Y;

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goRight (Event *)
    {
        positionX -= SPEED_X;

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::goDown (Event *)
    {
        printf("godown");

        positionY += SPEED_Y;

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goLeft (Event *)
    {

        printf("goleft");

        positionX += SPEED_X;

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        addTween(ColorRectSprite::TweenPosition(positionX, positionY),
                 TweenOptions(1).delay(delay).doneCallback(callback));
    }
}