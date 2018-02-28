#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include "oxygine-framework.h"
#include "../Objects/Size.h"

using namespace oxygine;

namespace System
{
    class Menu
    {
    public:
        Menu ();
        ~Menu ();

        void click (Event* event);

    private:
        spTextField text;
    };
}


#endif //SNAKE_MENU_H
