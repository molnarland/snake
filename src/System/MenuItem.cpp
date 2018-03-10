#include "MenuItem.h"

#include "Button/ButtonBlack.h"
#include "Text/TextMainButton.h"

namespace System
{
    MenuItem::MenuItem (const string& label) : label(label)
    {

    }

    void MenuItem::make (const ButtonTypes& buttonType, const TextTypes& textType)
    {
        this->makeButton(buttonType);
        /*this->makeTextField(textType);*/
    }

    void MenuItem::makeButton (const ButtonTypes& type)
    {
        switch (type)
        {
            case ButtonBlack:
                this->button = new Button::ButtonBlack;
                break;
            default:
                throw "Invalid button type";
        }

        this->button->make();
    }

    void MenuItem::makeTextField (const TextTypes& type)
    {
        switch (type)
        {
            case TextMainButton:
                this->textField = new Text::TextMainButton(this->label, "../data/res.xml");
                break;
            default:
                throw  "invalid text type";
        }

        this->textField->make();
    }

    Button::AbstractButton* MenuItem::get () const
    {
        /*this->button->addChild(this->textField);*/

        return this->button;
    }
}


