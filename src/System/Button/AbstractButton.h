#ifndef SNAKE_IBUTTONMAKER_H
#define SNAKE_IBUTTONMAKER_H


#include "../MenuItem.h"
#include "oxygine-framework.h"
#include "../../Objects/Position.h"
#include "../../Objects/Size.h"

using namespace oxygine;
using namespace std;
using namespace GameObject;

namespace System::Button
{
    class AbstractButton : public ColorRectSprite
    {
    public:
        AbstractButton (const unit_size_t& size, const position_t& position, const EventCallback& callback)
                : size(size),
                  position(position),
                  callback(callback)
        {};

        virtual void make () = 0;

    protected:
        const unit_size_t size;
        const position_t position;
        const EventCallback callback;
    };
}

#endif //SNAKE_IBUTTONMAKER_H
