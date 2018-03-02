#ifndef SNAKE_BUTTONBLACKMAKER_H
#define SNAKE_BUTTONBLACKMAKER_H


#include "../MenuItem.h"
#include "AbstractButton.h"

namespace System::Button
{
    class ButtonBlack: public AbstractButton
    {
    public:
        virtual void make ();
    };
}


#endif //SNAKE_BUTTONBLACKMAKER_H
