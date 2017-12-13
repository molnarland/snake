#include "Snake.h"
#include "oxygine-framework.h"



namespace Game
{
    Snake::Snake ()
    {
//        _canGo = canGo;

        bodies.push_back(new SnakeBody(10, 10, DELAY));
        bodies.push_back(new SnakeBody(9, 10, DELAY));

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

        start();
    }

    void Snake::start ()
    {
        throughAllBody([this] (unsigned long index)
                       {
                           this->bodies[index]->goRight(nullptr);
                       });
    }


    void Snake::throughAllBody (std::function <void (unsigned long index)> callback)
    {
        unsigned long snakeLength = bodies.size();

        for (unsigned long index = 0; index < snakeLength; index++)
        {
            callback(index);
        }
    }

    void Snake::moveUp (signed long index)
    {
        currentMoveDirection = Direction::UP;

        bodies[index]->goUp(nullptr);
    }

    void Snake::moveLeft (signed long index)
    {
        currentMoveDirection = Direction::LEFT;

        bodies[index]->goLeft(nullptr);
    }

    void Snake::moveDown (signed long index)
    {
        currentMoveDirection = Direction::DOWN;

        bodies[index]->goDown(nullptr);
    }

    void Snake::moveRight (signed long index)
    {
        currentMoveDirection = Direction::RIGHT;

        bodies[index]->goRight(nullptr);
    }

    bool Snake::canMoveUp ()
    {
        return bodies[0]->getCanMove()
               && (currentMoveDirection == Direction::RIGHT || currentMoveDirection == Direction::LEFT);
    }

    bool Snake::canMoveLeft ()
    {
        return bodies[0]->getCanMove()
               && (currentMoveDirection == Direction::UP || currentMoveDirection == Direction::DOWN);
    }

    bool Snake::canMoveDown ()
    {
        return canMoveUp();
    }

    bool Snake::canMoveRight ()
    {
        return canMoveLeft();
    }

    void Snake::pressArrow (Event* ev)
    {
        SDL_Event* event = (SDL_Event*) ev->userData;

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