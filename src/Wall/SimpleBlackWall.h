#ifndef SNAKE_SIMPLEBLACKWALL_H
#define SNAKE_SIMPLEBLACKWALL_H

#include "AbstractWall.h"

namespace Wall
{
    class SimpleBlackWall : public AbstractWall, public oxygine::ColorRectSprite
    {
    public:
        SimpleBlackWall (const GameObject::position_t& position, const GameObject::unit_size_t& size);

        void make ();
    };
}


#endif //SNAKE_SIMPLEBLACKWALL_H