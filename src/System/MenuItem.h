#ifndef SNAKE_MENUITEM_H
#define SNAKE_MENUITEM_H

#include "oxygine-framework.h"
#include "Button/AbstractButton.h"
#include "../Objects/ButtonTypes.h"
#include "../Objects/TextTypes.h"
#include "Text/AbstractText.h"
#include "../Objects/Size.h"

using namespace oxygine;
using namespace std;
using namespace GameObject;

namespace System
{
    class MenuItem
    {
    public:
        explicit MenuItem(const string& label, unit_size_t size, position_t position);

        void make(const ButtonTypes& buttonType, const TextTypes& textType);
        unit_size_t getSize();
        position_t getPosition();

        Button::AbstractButton* get () const;
    private:
        string label;
        unit_size_t size;
        position_t position;
        Text::AbstractText* textField;
        Button::AbstractButton* button;
//        Resources resources;

        void makeButton (const ButtonTypes& type);
        void makeTextField (const TextTypes& type);
    };
}


#endif //SNAKE_MENUITEM_H
