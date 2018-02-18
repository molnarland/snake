#include "Snake.h"
#include "oxygine-framework.h"
#include "../Food/SmallFood.h"

namespace Game
{
    Food::SmallFood* food;

    Snake::Snake (unit_size_t snakeBodySize)
    {
        bodySize = snakeBodySize;

        addBody(new SnakeBody({10 * snakeBodySize.width, 10 * snakeBodySize.height}, snakeBodySize));
        addBody(new SnakeBody({9 * snakeBodySize.width, 10 * snakeBodySize.height}, snakeBodySize));

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &Snake::pressArrow));

        food = new Food::SmallFood({20 * snakeBodySize.width, 20 * snakeBodySize.height});
    }

    void Snake::start ()
    {
        currentMoveDirection = GameObject::Direction::RIGHT;

        throughAllBody([this] (unsigned long index)
        {
            this->bodies[index]->directon = GameObject::Direction::RIGHT;
            this->bodies[index]->goRight(nullptr);
        });
    }

    void Snake::check ()
    {
        throughAllBody([this] (unsigned long index)
        {
            if (index > 0)
            {
                std::deque <GameObject::will_move_t> willMove = bodies[index]->getWillMoves();
                unsigned long willMoveLength = bodies[index]->willMoves.size();

                if (willMoveLength > 0)
                {
                    for (unsigned long moveIndex = 0; moveIndex < willMoveLength; moveIndex++)
                    {
                        bodies[index]->willMoves[moveIndex].steps--;
                    }

                    if (bodies[index]->willMoves[0].steps == 0)
                    {
                        bodies[index]->directon = bodies[index]->willMoves[0].directon;
                        bodies[index]->willMoves.pop_front();
                    }
                }
            }

            switch (bodies[index]->directon)
            {
                case GameObject::Direction::UP:
                    bodies[index]->goUp(nullptr);
                    break;
                case GameObject::Direction::LEFT:
                    bodies[index]->goLeft(nullptr);
                    break;
                case GameObject::Direction::DOWN:
                    bodies[index]->goDown(nullptr);
                    break;
                case GameObject::Direction::RIGHT:
                    bodies[index]->goRight(nullptr);
                    break;
                default:
                    break;
            }
        });


        GameObject::position_t headPosition = bodies[0]->getPosition();
        GameObject::position_t foodPosition = food->getCurrentPosition();


        printf("%lf - %lf - %lf - %lf \n", headPosition.x, foodPosition.x, headPosition.y, foodPosition.y);

        if ((int)headPosition.x == (int)foodPosition.x && (int)headPosition.y == (int)foodPosition.y)
        {
            this->addBody()
        }
    }

    void Snake::addBody (spSnakeBody snakeBody)
    {
        getStage()->addChild(snakeBody);
        bodies.push_back(snakeBody);
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
                bodies[index]->addWillMove(index + 1, direction);
            }, 1);
        }
    }

    void Snake::move (unsigned long index, char direction)
    {
        bodies[index]->directon = currentMoveDirection = direction;

        addWillMoveForAllBodies(direction, index);
    }

    void Snake::moveUp (unsigned long bodyIndex)
    {
        move(bodyIndex, GameObject::Direction::UP);
    }

    void Snake::moveLeft (unsigned long bodyIndex)
    {
        move(bodyIndex, GameObject::Direction::LEFT);
    }

    void Snake::moveDown (unsigned long bodyIndex)
    {
        move(bodyIndex, GameObject::Direction::DOWN);
    }

    void Snake::moveRight (unsigned long bodyIndex)
    {
        move(bodyIndex, GameObject::Direction::RIGHT);
    }

    bool Snake::canMoveUp ()
    {
        return bodies[0]->getCanMove()
               && (currentMoveDirection == GameObject::Direction::RIGHT || currentMoveDirection == GameObject::Direction::LEFT);
    }

    bool Snake::canMoveLeft ()
    {
        return bodies[0]->getCanMove()
               && (currentMoveDirection == GameObject::Direction::UP || currentMoveDirection == GameObject::Direction::DOWN);
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
            case SDLK_UP:
                if (canMoveUp())
                {
                    moveUp();
                }
                break;
            case SDLK_a:
            case SDLK_LEFT:
                if (canMoveLeft())
                {
                    moveLeft();
                }
                break;
            case SDLK_s:
            case SDLK_DOWN:
                if (canMoveDown())
                {
                    moveDown();
                }
                break;
            case SDLK_d:
            case SDLK_RIGHT:
                if (canMoveRight())
                {
                    moveRight();
                }
                break;
            default:
                break;
        }

    }
}