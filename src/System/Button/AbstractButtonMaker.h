#ifndef SNAKE_IBUTTONMAKER_H
#define SNAKE_IBUTTONMAKER_H


#include "../MenuItem.h"

namespace System::Button
{
    class AbstractButtonMaker
    {
    public:
        explicit AbstractButtonMaker (MenuItem& menuItem) : menuItem(menuItem)
        {};

        virtual void make () = 0;

    private:
        MenuItem& menuItem;
    };
}

#endif //SNAKE_IBUTTONMAKER_H
