#ifndef SNAKE_IBUTTONMAKER_H
#define SNAKE_IBUTTONMAKER_H


#include "../MenuItem.h"
#include "oxygine-framework.h"



using namespace oxygine;

namespace System::Button
{
    class AbstractButton: public ColorRectSprite
    {
    public:
        virtual void make () = 0;
    };
}

#endif //SNAKE_IBUTTONMAKER_H
