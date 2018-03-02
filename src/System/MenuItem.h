#ifndef SNAKE_MENUITEM_H
#define SNAKE_MENUITEM_H

#include "oxygine-framework.h"
#include "Button/AbstractButton.h"
#include "../Objects/ButtonTypes.h"
#include "../Objects/TextTypes.h"
#include "Text/AbstractText.h"

using namespace oxygine;
using namespace std;
using namespace GameObject;

namespace System
{
    class MenuItem
    {
    public:
        explicit MenuItem(string label);

        void make(ButtonTypes buttonType, TextTypes textType);
        Button::AbstractButton* get ();
    private:
        string label;
        Text::AbstractText* textField;
        Button::AbstractButton* button;
//        Resources resources;

        void makeButton (ButtonTypes type);
        void makeTextField (TextTypes type);
    };
}


#endif //SNAKE_MENUITEM_H
