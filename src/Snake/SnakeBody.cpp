#include <ox/oxygine.hpp>
#include "SnakeBody.h"

namespace Snake
{
    SnakeBody::SnakeBody (position_t startPosition, unit_size_t snakeBodySize)
    {
        this->_positionX = startPosition.x;
        this->_positionY = startPosition.y;
        this->size = snakeBodySize;
        this->stepSize = {size.width, size.height};

        setSize(this->size.width, this->size.height);
        setColor(0, 0, 0, 255);
        setPosition((float) this->_positionX, (float) this->_positionY);
        attachTo(getStage());
    }

    void SnakeBody::addWillMove (unsigned long steps, char direction)
    {
        this->willMoves.push_back({steps, direction});
    }

    std::deque<will_move_t> SnakeBody::getWillMoves ()
    {
        return this->willMoves;
    }

    void SnakeBody::removeFirstMove ()
    {
        this->willMoves.pop_front();
    }

    bool SnakeBody::getCanMove ()
    {
        return this->_canMove;
    }

    void SnakeBody::setCanMove (bool canMove)
    {
        this->_canMove = canMove;
    }

    void SnakeBody::goUp (Event *)
    {
        if (this->_canMove)
        {
            this->_positionY -= this->stepSize.y;
            this->direction = Direction::UP;
        }
        else
        {
            this->setCanMove(true);
        }

        this->go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goLeft (Event *)
    {
        if (this->_canMove)
        {
            this->_positionX -= this->stepSize.x;
            this->direction = Direction::LEFT;
        }
        else
        {
            this->setCanMove(true);
        }

        this->go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::goDown (Event *)
    {
        if (this->_canMove)
        {
            this->_positionY += this->stepSize.y;
            this->direction = Direction::DOWN;
        }
        else
        {
            this->setCanMove(true);
        }

        this->go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goRight (Event *)
    {
        if (this->_canMove)
        {
            this->_positionX += this->stepSize.x;
            this->direction = Direction::RIGHT;
        }
        else
        {
            this->setCanMove(true);
        }

        this->go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        this->addTween(ColorRectSprite::TweenPosition((int) this->_positionX, (int) this->_positionY), 1);
    }

    position_t SnakeBody::getPosition ()
    {
        return {this->_positionX, this->_positionY};
    }
}
