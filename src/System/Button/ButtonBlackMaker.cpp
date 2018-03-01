#include "ButtonBlackMaker.h"

namespace System::Button
{

    ButtonBlackMaker::ButtonBlackMaker (MenuItem& menuItem) : AbstractButtonMaker(menuItem)
    {

    }

    void ButtonBlackMaker::make ()
    {
        this->menuItem->setColor(0, 0, 0, 1);
        this->menuItem->setSize(100, 100);
        this->menuItem->setPosition(300, 300);
    }
}