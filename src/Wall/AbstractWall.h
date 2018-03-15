#ifndef SNAKE_ABSTRACTWALL_H
#define SNAKE_ABSTRACTWALL_H

#include <oxygine-framework.h>
#include "../Objects/Position.h"
#include "../Objects/Size.h"

namespace Wall
{
    const GameObject::unit_size_t preComputedSize = {
            oxygine::getStage()->getWidth() / 50,
            oxygine::getStage()->getHeight() / (50 / (oxygine::getStage()->getWidth()
                                                      / oxygine::getStage()->getHeight()))
    };

    class AbstractWall
    {
    public:
        explicit AbstractWall (const GameObject::position_t& position) : position(position), size(preComputedSize)
        {};

        virtual void make () = 0;

        GameObject::position_t getPosition ()
        { this->position; }

    protected:
        const GameObject::position_t position;
        const GameObject::unit_size_t size;
    };
}

#endif //SNAKE_ABSTRACTWALL_H
