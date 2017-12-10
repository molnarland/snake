#include "Snake.h"
#include "oxygine-framework.h"

namespace Kigyo
{
    Snake::Snake ()
    {
        bodies[0] = new SnakeBody;

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

        moveRight();
    }

    void Snake::moveUp ()
    {
        currentMoveDirection = MOVE_UP;

        bodies[0]->goUp(NULL);
    }

    void Snake::moveLeft ()
    {
        currentMoveDirection = MOVE_LEFT;

        bodies[0]->goLeft(NULL);
    }

    void Snake::moveDown ()
    {
        currentMoveDirection = MOVE_DOWN;

        bodies[0]->goDown(NULL);
    }

    void Snake::moveRight ()
    {
        currentMoveDirection = MOVE_RIGHT;

        bodies[0]->goRight(NULL);
    }

    bool Snake::canMoveUp ()
    {
        return currentMoveDirection == MOVE_RIGHT || currentMoveDirection == MOVE_LEFT;
    }

    bool Snake::canMoveLeft ()
    {
        return currentMoveDirection == MOVE_UP || currentMoveDirection == MOVE_DOWN;
    }

    bool Snake::canMoveDown ()
    {
        return canMoveUp();
    }

    bool Snake::canMoveRight ()
    {
        return canMoveLeft();
    }

    void Snake::pressArrow (Event *ev)
    {
        SDL_Event *event = (SDL_Event *) ev->userData;

        if (event->type != SDL_KEYDOWN)
        {
            return;
        }

        switch (event->key.keysym.sym)
        {
            case SDLK_w:
                if (canMoveUp())
                {
                    bodies[0]->removeTweens();
                    moveUp();
                }
                break;
            case SDLK_a:
                if (canMoveLeft())
                {
                    bodies[0]->removeTweens();
                    moveLeft();
                }
                break;
            case SDLK_s:
                if (canMoveDown())
                {
                    bodies[0]->removeTweens();
                    moveDown();
                }
                break;
            case SDLK_d:
                if (canMoveRight())
                {
                    bodies[0]->removeTweens();
                    moveRight();
                }
                break;
            default:
                break;
        }
    }
}