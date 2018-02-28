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



        spTextField text = new TextField();
        text->setPosition(400, 400);
        text->setSize(100, 100);
        text->setStyle(TextStyle(gameResources.getResFont("main")).withColor(Color::White).alignMiddle());
        text->setText("Start");
        text->attachTo(stage);

        text->addEventListener(TouchEvent::CLICK, CLOSURE(this, &Menu::click));

        this->text = text;
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