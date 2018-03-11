/*v0.1*/
#include "System/Game.h"
#include "System/Menu.h"

using namespace System;

Game* game;
bool firstMove = true;
Menu* menu;

void preinit () {}

void init ()
{
    //TODO add snake body size as a constant
    /*unit_size_t snakeBodySize = {
            .width = oxygine::getStage()->getWidth() / 50,
            .height = oxygine::getStage()->getHeight() /
                      (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))
    };*/


    game = new Game();
    menu = new Menu(game);
}

void update ()
{
    game->check();
}

void destroy () {}