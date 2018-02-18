#include <core/oxygine.h>
#include "SnakeBody.h"

namespace Snake
{
    SnakeBody::SnakeBody (GameObject::position_t startPosition, unit_size_t snakeBodySize)
    {
        _positionX = startPosition.x;
        _positionY = startPosition.y;
        size = snakeBodySize;
        stepSize = {size.width, size.height};

        setSize(size.width, size.height);
        setColor(0, 0, 0, 255);
        setPosition((float) _positionX, (float) _positionY);
        attachTo(getStage());
    }

    void SnakeBody::addWillMove (unsigned long steps, char direction)
    {
        this->willMoves.push_back({steps, direction});
    }

    std::deque<GameObject::will_move_t> SnakeBody::getWillMoves ()
    {
        return this->willMoves;
    }

    void SnakeBody::removeFirstMove ()
    {
        this->willMoves.pop_front();
    }

    bool SnakeBody::getCanMove ()
    {
        return _canMove;
    }

    void SnakeBody::setCanMove (bool canMove)
    {
        _canMove = canMove;
    }

    void SnakeBody::goUp (Event *)
    {
        if (_canMove)
        {
            _positionY -= stepSize.y;
            directon = GameObject::Direction::UP;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goUp));
    }

    void SnakeBody::goLeft (Event *)
    {
        if (_canMove)
        {
            _positionX -= stepSize.x;
            directon = GameObject::Direction::LEFT;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goLeft));
    }

    void SnakeBody::goDown (Event *)
    {
        if (_canMove)
        {
            _positionY += stepSize.y;
            directon = GameObject::Direction::DOWN;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goDown));
    }

    void SnakeBody::goRight (Event *)
    {
        if (_canMove)
        {
            _positionX += stepSize.x;
            directon = GameObject::Direction::RIGHT;
        }
        else
        {
            setCanMove(true);
        }

        go(CLOSURE(this, &SnakeBody::goRight));
    }

    void SnakeBody::go (const EventCallback &callback)
    {
        addTween(ColorRectSprite::TweenPosition((int) _positionX, (int) _positionY), 1);
    }

    GameObject::position_t SnakeBody::getPosition ()
    {
        return {_positionX, _positionY};
    }
}