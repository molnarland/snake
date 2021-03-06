#include "Menu.h"

using namespace Global;

namespace System
{
    Menu::Menu (Game* game) : game(game)
    {
        spStage stage = getStage();
        Vector2 stageSize = stage->getSize();

        this->setSize(Percentage::calculate(stageSize.x, 60), Percentage::calculate(stageSize.y, 90));
        this->setPosition(Percentage::calculate(stageSize.x, 20), Percentage::calculate(stageSize.y, 5));
        this->setColor(Color(255, 102, 204));

        this->attachTo(stage);

        this->itemsMarginTop = Percentage::calculate(getSize().y, 3);
        this->itemsHeight = Percentage::calculate(getSize().y, 2.5);
        this->menuPaddingLeftAndRight = Percentage::calculate(getSize().x, 5);

        this->addMenuItems();
    }

    Menu::~Menu ()
    {
    }

    Game* Menu::start (Event*)
    {
        this->game->make();
        this->game->start();

        this->detach();
    }

    void Menu::addMenuItems ()
    {
        this->addMenuItem(ButtonBlack, TextMainButton, CLOSURE(this, &Menu::start));
        this->addMenuItem(ButtonBlack, TextMainButton, [](Event*) { log::messageln("jeeeh"); });
    }

    void Menu::addMenuItem (const ButtonTypes& buttonType, const TextTypes& textType, const EventCallback& callback)
    {
        MenuItem* menuItem = new MenuItem("Start", this->getNextItemSize(), this->getNextItemPosition(), callback);
        menuItem->make(buttonType, textType);
        this->addChild(menuItem->get());

        this->menuItems.push_back(menuItem);
    }

    position_t Menu::getNextItemPosition ()
    {
        double positionY;
        if (this->menuItems.empty())
        {
            positionY = this->itemsMarginTop;
        }
        else
        {
            MenuItem* lastMenuItem = this->menuItems.back();
            positionY = lastMenuItem->getPosition().y + lastMenuItem->getSize().height + this->itemsMarginTop;
        }

        return {this->menuPaddingLeftAndRight, positionY};
    }

    unit_size_t Menu::getNextItemSize ()
    {
        return {
                this->getSize().x - this->menuPaddingLeftAndRight * 2,
                Percentage::calculate(this->getSize().y, this->itemsHeight)
        };
    }
}