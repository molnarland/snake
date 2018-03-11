#include "SnakeNervousSystem.h"
#include "oxygine-framework.h"
#include "../Food/SmallFood.h"

namespace Snake
{
    SnakeNervousSystem::SnakeNervousSystem (unit_size_t snakeBodySize) : DELAY(100)
    {
        this->bodySize = snakeBodySize;

        this->addBody(new SnakeBody({10 * this->bodySize.width, 10 * this->bodySize.height}, this->bodySize));
        this->addBody(new SnakeBody({9 * this->bodySize.width, 10 * this->bodySize.height}, this->bodySize));

        core::getDispatcher()->addEventListener(core::EVENT_SYSTEM, CLOSURE(this, &SnakeNervousSystem::pressArrow));
    }

    void SnakeNervousSystem::start ()
    {
        this->currentMoveDirection = GameObject::Direction::RIGHT;

        throughAllBody([this] (unsigned long index)
        {
            this->bodies[index]->directon = this->currentMoveDirection;
            this->bodies[index]->goRight(nullptr);
        });
    }

    void SnakeNervousSystem::check ()
    {
        this->canMove = true;

        this->throughAllBody([this] (unsigned long index)
        {
            if (index > 0)
            {
                std::deque <GameObject::will_move_t> willMove = this->bodies[index]->getWillMoves();
                unsigned long willMoveLength = this->bodies[index]->willMoves.size();

                if (willMoveLength > 0)
                {
                    for (unsigned long moveIndex = 0; moveIndex < willMoveLength; moveIndex++)
                    {
                        this->bodies[index]->willMoves[moveIndex].steps =
                                this->bodies[index]->willMoves[moveIndex].steps - 1;
                    }

                    if (this->bodies[index]->willMoves[0].steps <= 0)
                    {
                        this->bodies[index]->directon = this->bodies[index]->willMoves[0].direction;
                        this->bodies[index]->removeFirstMove();
                    }
                }
            }

            this->goSomewhere(this->bodies[index]->directon, index);

            /*switch (bodies[index]->direction)
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
            }*/
        });
    }

    void SnakeNervousSystem::addBody (spSnakeBody snakeBody)
    {
        getStage()->addChild(snakeBody);
        this->bodies.push_back(snakeBody);
    }

    void SnakeNervousSystem::throughAllBody (std::function <void (unsigned long index)> callback, unsigned long from)
    {
        unsigned long snakeLength = this->bodies.size();

        for (unsigned long index = from; index < snakeLength; index++)
        {
            callback(index);
        }
    }

    void SnakeNervousSystem::addWillMoveForAllBodies (char direction, unsigned long bodyIndex)
    {
        if (bodyIndex == 0)
        {
            throughAllBody([this, direction] (unsigned long index)
            {
                this->bodies[index]->addWillMove(index + 1, direction);
            }, 1);
        }
    }

    void SnakeNervousSystem::move (unsigned long index, char direction)
    {
        this->canMove = false;

        this->bodies[index]->directon = this->currentMoveDirection = direction;

        addWillMoveForAllBodies(direction, index);
    }

    void SnakeNervousSystem::moveUp (unsigned long bodyIndex)
    {
        this->move(bodyIndex, Direction::UP);
    }

    void SnakeNervousSystem::moveLeft (unsigned long bodyIndex)
    {
        this->move(bodyIndex, Direction::LEFT);
    }

    void SnakeNervousSystem::moveDown (unsigned long bodyIndex)
    {
        this->move(bodyIndex, Direction::DOWN);
    }

    void SnakeNervousSystem::moveRight (unsigned long bodyIndex)
    {
        this->move(bodyIndex, Direction::RIGHT);
    }

    bool SnakeNervousSystem::canMoveUp ()
    {
        return this->bodies[0]->getCanMove()
               && (this->currentMoveDirection == Direction::RIGHT ||
                this->currentMoveDirection == Direction::LEFT);
    }

    bool SnakeNervousSystem::canMoveLeft ()
    {
        return bodies[0]->getCanMove()
               && (currentMoveDirection == GameObject::Direction::UP ||
                   currentMoveDirection == GameObject::Direction::DOWN);
    }

    bool SnakeNervousSystem::canMoveDown ()
    {
        return canMoveUp();
    }

    bool SnakeNervousSystem::canMoveRight ()
    {
        return canMoveLeft();
    }

    void SnakeNervousSystem::pressArrow (Event* ev)
    {
        if (!this->canMove)
        {
            return;
        }

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

    size_t SnakeNervousSystem::getBodyLength ()
    {
        return this->bodies.size();
    }

    spSnakeBody SnakeNervousSystem::getOneBody (unsigned long index)
    {
        return this->bodies[index];
    }

    spSnakeBody SnakeNervousSystem::getHead ()
    {
        return this->getOneBody(0);
    }

    void SnakeNervousSystem::grow ()
    {
        //TODO addWillMove and position set don't work correctly here if last part (not what growing) gonna move somewhere
        size_t bodyLength = this->getBodyLength();
        position_t lastBodyPosition = this->bodies.back()->getPosition();
        unit_size_t bodySize = this->bodySize;
        double positionX;
        double positionY;

        this->checkDirection(
                this->getOneBody(bodyLength - 1)->directon,
                [&] () //up
                {
                    positionX = lastBodyPosition.x;
                    positionY = lastBodyPosition.y + bodySize.height * 2;
                },
                [&] () //left
                {
                    positionX = lastBodyPosition.x + bodySize.width * 2;
                    positionY = lastBodyPosition.y;
                },
                [&] () //down
                {
                    positionX = lastBodyPosition.x;
                    positionY = lastBodyPosition.y - bodySize.height * 2;
                },
                [&] () //right
                {
                    positionX = lastBodyPosition.x - bodySize.width * 2;
                    positionY = lastBodyPosition.y;
                }
        );

        this->addBody(new SnakeBody({positionX, positionY}, this->bodySize));

        spSnakeBody body = this->bodies.back();
        std::deque<GameObject::will_move_t> beforeLastBodyWillMoves = this->getOneBody(this->getBodyLength() - 2)->getWillMoves();
        size_t beforeLastBodyWillMovesLength = beforeLastBodyWillMoves.size();

        for (unsigned long index = 1; index <= beforeLastBodyWillMovesLength; index++)
        {
            unsigned long steps = (index > 1) ? index - 1 : index;
            char direction = beforeLastBodyWillMoves[index].direction;

            direction = (direction != Direction::RIGHT && direction != Direction::UP
                         && direction != Direction::LEFT && direction != Direction::DOWN)
                        ? this->currentMoveDirection
                        : direction;

            body->addWillMove(steps, direction);
        }

        this->goSomewhere(this->bodies[bodyLength - 2]->directon, bodyLength);
    }

    void SnakeNervousSystem::checkDirection (char direction, function <void ()> up, function <void ()> left,
                                             function <void ()> down, function <void ()> right)
    {
        switch (direction)
        {
            case Direction::UP:
                up();
                break;
            case Direction::LEFT:
                left();
                break;
            case Direction::DOWN:
                down();
                break;
            case Direction::RIGHT:
                right();
                break;
            default:
                break;
        }
    }

    void SnakeNervousSystem::goSomewhere (char direction, unsigned long bodyIndex)
    {
        spSnakeBody body = this->bodies[bodyIndex];

        this->checkDirection(
                direction,
                [body] () { body->goUp(nullptr); },
                [body] () { body->goLeft(nullptr); },
                [body] () { body->goDown(nullptr); },
                [body] () { body->goRight(nullptr); }
        );
    }
}