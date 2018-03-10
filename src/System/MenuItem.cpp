#include "MenuItem.h"

#include "Button/ButtonBlack.h"
#include "Text/TextMainButton.h"

namespace System
{
    MenuItem::MenuItem (const string& label, const unit_size_t& size, const position_t& position, const EventCallback& callback)
            : label(label), size(size), position(position), callback(callback)
    {}

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
                this->button = new Button::ButtonBlack(this->size, this->position, this->callback);
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

    unit_size_t MenuItem::getSize ()
    {
        return this->size;
    }

    position_t MenuItem::getPosition ()
    {
        return this->position;
    }
}


