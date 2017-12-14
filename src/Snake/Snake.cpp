#include "Snake.h"
#include "oxygine-framework.h"



namespace Game
{
    Snake::Snake ()
    {
        bodies.push_back(new SnakeBody(10, 10, DELAY));
        bodies.push_back(new SnakeBody(9, 10, DELAY));
        bodies.push_back(new SnakeBody(8, 10, DELAY));
//        bodies.push_back(new SnakeBody(7, 10, DELAY));

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

    void Snake::check ()
    {
        throughAllBody([this](unsigned long index) {
//            std::deque<will_move_t> willMove = bodies[index]->getWillMoves();
            unsigned long willMoveLength = bodies[index]->willMoves.size();

            if (willMoveLength > 0)
            {
                for (unsigned long moveIndex = 0; moveIndex < willMoveLength; moveIndex++)
                {
                    bodies[index]->willMoves[moveIndex].steps--;
                }

                printf("%d - %c: %d\n",
                       bodies[index]->willMoves[0].steps,
                       (char16_t)bodies[index]->willMoves[0].directon,
                       index);

                if (bodies[index]->willMoves[0].steps == 0)
                {
                    bodies[index]->removeTweens(false);
//                    bodies[index]->setCanMove(false);

//                    printf("%c\n", (char16_t )bodies[index]->willMoves[0].directon);

                    switch (bodies[index]->willMoves[0].directon)
                    {
                        case Direction::UP:
                            bodies[index]->goUp(nullptr);
                            break;
                        case Direction::LEFT:
                            bodies[index]->goLeft(nullptr);
                            break;
                        case Direction::DOWN:
                            bodies[index]->goDown(nullptr);
                            break;
                        case Direction::RIGHT:
                            bodies[index]->goRight(nullptr);
                            break;
                        default:
                            break;
                    }

                    bodies[index]->removeFirstMove();
                }
            }
        }, 1);
    }

    void Snake::throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from)
    {
        unsigned long snakeLength = bodies.size();

        for (unsigned long index = from; index < snakeLength; index++)
        {
            callback(index);
        }
    }

    void Snake::addWillMoveForAllBodies (char direction, unsigned long bodyIndex)
    {
        if (bodyIndex == 0)
        {
            throughAllBody([this, direction] (unsigned long index)
                           {
                               bodies[index]->addWillMove(index+2, direction);
                           }, 1);
        }
    }

    void Snake::moveUp (unsigned long bodyIndex)
    {
        char direction = currentMoveDirection = Direction::UP;

        bodies[bodyIndex]->goUp(nullptr);

        addWillMoveForAllBodies(direction, bodyIndex);
    }

    void Snake::moveLeft (unsigned long bodyIndex)
    {
        char direction = currentMoveDirection = Direction::LEFT;

        bodies[bodyIndex]->goLeft(nullptr);

        addWillMoveForAllBodies(direction, bodyIndex);
    }

    void Snake::moveDown (unsigned long bodyIndex)
    {
        char direction = currentMoveDirection = Direction::DOWN;

        bodies[bodyIndex]->goDown(nullptr);

        addWillMoveForAllBodies(direction, bodyIndex);
    }

    void Snake::moveRight (unsigned long bodyIndex)
    {
        char direction = currentMoveDirection = Direction::RIGHT;

        bodies[bodyIndex]->goRight(nullptr);

        addWillMoveForAllBodies(direction, bodyIndex);
    }

    bool Snake::canMoveUp ()
    {
        /*printf("%d - %d - %c\n", bodies[0]->getCanMove(), (currentMoveDirection == Direction::RIGHT ||
                currentMoveDirection == Direction::LEFT), currentMoveDirection);*/
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