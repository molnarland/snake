#include "Snake.h"
#include "oxygine-framework.h"



namespace Game
{
    Snake::Snake ()
    {
        bodies.push_back(new SnakeBody(10, 10, DELAY));
        bodies.push_back(new SnakeBody(9, 10, DELAY));

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

        start();
    }

    void Snake::start ()
    {
        currentMoveDirection = Direction::RIGHT;

        throughAllBody([this] (unsigned long index)
                       {
                           this->bodies[index]->goRight(nullptr);
                       });
    }


    void Snake::throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from)
    {
        unsigned long snakeLength = bodies.size();

        for (unsigned long index = from; index < snakeLength; index++)
        {
            callback(index);
        }
    }

    void Snake::moveUp (signed long bodyIndex)
    {
        char direction = currentMoveDirection = Direction::UP;

        bodies[bodyIndex]->goUp(nullptr);

        if (bodyIndex == 0)
        {
            throughAllBody([this, direction] (unsigned long index)
                           {
                               bodies[index]->addWillMove(index, direction);
                           }, 1);
        }
    }

    void Snake::moveLeft (signed long bodyIndex)
    {
        currentMoveDirection = Direction::LEFT;

        bodies[bodyIndex]->goLeft(nullptr);
    }

    void Snake::moveDown (signed long bodyIndex)
    {
        currentMoveDirection = Direction::DOWN;

        bodies[bodyIndex]->goDown(nullptr);
    }

    void Snake::moveRight (signed long bodyIndex)
    {
        currentMoveDirection = Direction::RIGHT;

        bodies[bodyIndex]->goRight(nullptr);
    }

    bool Snake::canMoveUp ()
    {
        printf("%d - %d - %c\n", bodies[0]->getCanMove(), (currentMoveDirection == Direction::RIGHT ||
                currentMoveDirection == Direction::LEFT), currentMoveDirection);
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