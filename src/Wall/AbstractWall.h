#ifndef SNAKE_ABSTRACTWALL_H
#define SNAKE_ABSTRACTWALL_H

#include <oxygine-framework.h>
#include "../Objects/Position.h"
#include "../Objects/Size.h"

namespace Wall
{
    class AbstractWall
    {
    public:
        virtual void make () = 0;

        const GameObject::position_t& getPosition ()
        { this->position; }

    protected:
        GameObject::position_t position;
        GameObject::unit_size_t size;
    };
}

#endif //SNAKE_ABSTRACTWALL_H
