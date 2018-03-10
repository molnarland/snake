#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include "oxygine-framework.h"
#include "../Objects/Size.h"
#include "MenuItem.h"
#include "../Global/Percentage.h"

using namespace oxygine;
using namespace std;
using namespace Global;

namespace System
{
    class Menu: public ColorRectSprite
    {
    public:
        Menu ();
        ~Menu ();

    private:
        deque<MenuItem*> menuItems;
        float itemsMarginTop;
        float itemsHeight;
        float menuPaddingLeftAndRight;

        void addMenuItems();
        void addMenuItem(const ButtonTypes& buttonType, const TextTypes& textType);
        position_t getNextItemPosition();
        unit_size_t getNextItemSize();
    };
}


#endif //SNAKE_MENU_H
