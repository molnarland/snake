#include "Snake.h"
#include "oxygine-framework.h"

namespace Kigyo
{
    Snake::Snake ()
    {
        bodies[0] = new SnakeBody;

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

        bodies[0]->goLeft(NULL);
    }


    void Snake::pressArrow (Event *ev)
    {
        SDL_Event *event = (SDL_Event *) ev->userData;

        if (event->type != SDL_KEYDOWN)
        {
            return;
        }

        bodies[0]->removeTweens();

        switch (event->key.keysym.sym)
        {
            case SDLK_w:
                bodies[0]->goUp(NULL);
                break;
            case SDLK_a:
                bodies[0]->goRight(NULL);
                break;
            case SDLK_s:
                bodies[0]->goDown(NULL);
                break;
            case SDLK_d:
                bodies[0]->goLeft(NULL);
                break;
            default:
                break;
        }

    }
}