#include "Snake.h"
#include "oxygine-framework.h"
#include "Directions.h"

namespace Kigyo
{
    Snake::Snake (bool *canGo)
    {
        _canGo = canGo;

        bodies[0] = new SnakeBody(10, 10, DELAY);

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

//        moveRight();
    }

    void Snake::moveUp ()
    {
        currentMoveDirection = DIRECTIONS.UP;

//        bodies[0]->setDirection(DIRECTIONS.UP);
        bodies[0]->goUp(NULL);
    }

    void Snake::moveLeft ()
    {
        currentMoveDirection = DIRECTIONS.LEFT;

        bodies[0]->goLeft(NULL);
    }

    void Snake::moveDown ()
    {
        currentMoveDirection = DIRECTIONS.DOWN;

        bodies[0]->goDown(NULL);
    }

    void Snake::moveRight ()
    {
        currentMoveDirection = DIRECTIONS.RIGHT;

        bodies[0]->goRight(NULL);
    }


    bool Snake::canMoveUp ()
    {
        return currentMoveDirection == DIRECTIONS.RIGHT || currentMoveDirection == DIRECTIONS.LEFT;
    }

    bool Snake::canMoveLeft ()
    {
        return currentMoveDirection == DIRECTIONS.UP || currentMoveDirection == DIRECTIONS.DOWN;
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
        if (!bodies[0]->dontMove)
        {
            SDL_Event *event = (SDL_Event *) ev->userData;

            if (event->type != SDL_KEYDOWN)
            {
                return;
            }

            SDL_Keycode keycode = event->key.keysym.sym;

            switch (keycode)
            {
                case SDLK_w:
                    if (canMoveUp())
                    {
                        bodies[0]->dontMove = true;
                        bodies[0]->removeTweens();
//                    sleep(getTimeMS() % DELAY);
                        moveUp();
                    }
                    break;
                case SDLK_a:
                    if (canMoveLeft())
                    {
                        bodies[0]->dontMove = true;
                        bodies[0]->removeTweens();
//                    sleep(getTimeMS() % DELAY);
                        moveLeft();
                    }
                    break;
                case SDLK_s:
                    if (canMoveDown())
                    {
                        bodies[0]->dontMove = true;
                        bodies[0]->removeTweens();
//                    sleep(getTimeMS() % DELAY);
                        moveDown();
                    }
                    break;
                case SDLK_d:
                    if (canMoveRight())
                    {
                        bodies[0]->dontMove = true;
                        bodies[0]->removeTweens();
//                    sleep(getTimeMS() % DELAY);
                        moveRight();
                    }
                    break;
                default:
                    break;
            }
        }
    }
}