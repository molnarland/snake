#include "MenuItem.h"
#include "Menu.h"
#include "Button/ButtonBlackMaker.h"

namespace System
{
    MenuItem::MenuItem (std::string label)
    {
        this->label = label;

        Resources resources;
        bool success = resources.loadXML("res.xml");

        if (success)
        {
            this->resources = &resources;
        }

        this->make();
    }


    MenuItem::MenuItem (std::string label, Resources* resources)
    {
        this->label = label;
        this->resources = resources;

        this->make();
    }

    void MenuItem::make ()
    {
        this->makeButton();
        this->makeTextField();

        this->textField->attachTo(this);
    }

    void MenuItem::makeButton ()
    {
        new Button::ButtonBlackMaker(*this);
    }

    void MenuItem::makeTextField ()
    {
        this->textField = new TextField();
        this->textField->setPosition(400, 400);
        this->textField->setSize(100, 100);
        this->textField->setStyle(TextStyle(this->resources->getResFont("main"))/*.withColor(Color::White)*/.alignMiddle());
        this->textField->setText(this->label);
//        text->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Menu::click));
    }
}

