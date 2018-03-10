#ifndef SNAKE_BUTTONBLACKMAKER_H
#define SNAKE_BUTTONBLACKMAKER_H


#include "../MenuItem.h"
#include "AbstractButton.h"

namespace System::Button
{
    class ButtonBlack: public AbstractButton
    {
    public:
        ButtonBlack (const unit_size_t& size, const position_t& position);

        virtual void make ();
    };
}


#endif //SNAKE_BUTTONBLACKMAKER_H
