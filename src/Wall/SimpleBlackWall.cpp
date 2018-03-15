#include "SimpleBlackWall.h"

namespace Wall
{
    SimpleBlackWall::SimpleBlackWall (const GameObject::position_t& position) : AbstractWall(position)
    {}

    void SimpleBlackWall::make ()
    {
        this->setSize(this->size.width, this->size.height);
        this->setColor(0, 0, 0, 255);
        this->setPosition((float) this->position.x, (float) this->position.y);
        this->attachTo(oxygine::getStage());
    }
}