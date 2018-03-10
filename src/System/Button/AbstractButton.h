#ifndef SNAKE_IBUTTONMAKER_H
#define SNAKE_IBUTTONMAKER_H


#include "../MenuItem.h"
#include "oxygine-framework.h"
#include "../../Objects/Position.h"
#include "../../Objects/Size.h"


using namespace oxygine;
using namespace GameObject;

namespace System::Button
{
    class AbstractButton : public ColorRectSprite
    {
    public:
        AbstractButton (unit_size_t size, position_t position) : size(size), position(position) {};

        virtual void make () = 0;

    protected:
        unit_size_t size;
        position_t position;
    };
}

#endif //SNAKE_IBUTTONMAKER_H
