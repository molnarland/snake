#include "Menu.h"
#include "Game.h"
#include "MenuItem.h"

Resources gameResources;

namespace System
{
    Menu::Menu ()
    {
        gameResources.loadXML("res.xml");

        getStage()->addChild(new MenuItem("Start", &gameResources));
    }

    void Menu::click (Event* event)
    {
        log::messageln("cliiick");
    }

    Menu::~Menu ()
    {
        gameResources.free();
    }
}