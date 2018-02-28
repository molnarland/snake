/*v0.1*/
#include <core/oxygine.h>
#include "System/Game.h"
#include "System/Menu.h"

//System::Game* game;
bool firstMove = true;

void example_preinit () {}

void example_init ()
{
    //TODO add snake body size as a constant
    /*unit_size_t snakeBodySize = {
            .width = oxygine::getStage()->getWidth() / 50,
            .height = oxygine::getStage()->getHeight() /
                      (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))
    };*/

    System::Menu* menu = new System::Menu();


//    game = new System::Game();
}

void example_update()
{
//    if (firstMove)
//    {
//        firstMove = false;
//        game->start();
//    }
//    else
//    {
//        game->check();
//    }
//
//    oxygine::sleep(100);
}

void example_destroy() {}