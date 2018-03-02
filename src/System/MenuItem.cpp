#include "MenuItem.h"

#include "Button/ButtonBlack.h"
#include "Text/TextMainButton.h"

namespace System
{
    MenuItem::MenuItem (string label) : label(move(label))
    {

    }

    void MenuItem::make (ButtonTypes buttonType, TextTypes textType)
    {
        this->makeButton(buttonType);
        this->makeTextField(textType);
    }

    void MenuItem::makeButton (ButtonTypes type)
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

    void MenuItem::makeTextField (TextTypes type)
    {
        /*Resources resources;
        if (resources.loadXML("res.xml"))
        {
            log::messageln("reeeeeeeeeeeeeeeeeeeees");

            ResFont* font = resources.getResFont("main");
            TextStyle style = TextStyle(font).alignMiddle();

            this->textField->setPosition(0, 0);
            this->textField->setSize(100, 100);
//            this->textField->setStyle(style);
            this->textField->setText(this->label);
        }*/

        switch (type)
        {
            case TextMainButton:
                this->textField = new Text::TextMainButton(this->label, "res.xml");
                break;
            default:
                throw  "invalid text type";
        }

        this->textField->make();
    }

    Button::AbstractButton* MenuItem::get ()
    {
        this->button->addChild(this->textField);

        return this->button;
    }
}


