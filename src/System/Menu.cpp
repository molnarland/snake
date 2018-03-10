#include "Menu.h"
#include "Game.h"
#include "MenuItem.h"

namespace System
{
    Menu::Menu ()
    {

        MenuItem* menuItem = new MenuItem("Start");
        menuItem->make(ButtonBlack, TextMainButton);
        getStage()->addChild(menuItem->get());
    }

    void Menu::click (Event* event)
    {
        log::messageln("cliiick");
    }

    Menu::~Menu ()
    {
    }
}