#include "ButtonBlack.h"

namespace System::Button
{
    void ButtonBlack::make ()
    {
        this->setColor(Color(10, 10, 10));
        this->setSize(100, 100);
        this->setPosition(300, 300);
    }
}