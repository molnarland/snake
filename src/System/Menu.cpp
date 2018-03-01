#include "Menu.h"
#include "Game.h"

Resources gameResources;

namespace System
{
    Menu::Menu ()
    {
        gameResources.loadXML("res.xml");

        const spStage& stage = getStage();
        const Vector2 stageSize = stage->getSize();
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