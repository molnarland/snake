#ifndef SNAKE_BUTTONBLACKMAKER_H
#define SNAKE_BUTTONBLACKMAKER_H


#include "../MenuItem.h"
#include "AbstractButtonMaker.h"

namespace System::Button
{
    class ButtonBlackMaker: public AbstractButtonMaker
    {
    public:
        explicit ButtonBlackMaker(MenuItem* menuItem);

        MenuItem* make ();
    };
}


#endif //SNAKE_BUTTONBLACKMAKER_H
