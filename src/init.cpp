#include <iostream>
#include <core/oxygine.h>
#include "Snake/Snake.h"

Game::Snake* snake;
bool canGo = true;
bool firstMove = true;

void example_preinit () {}

/*void bla (oxygine::ColorRectSprite *sprite, int where)
{
    sprite->addTween(
            oxygine::ColorRectSprite::TweenPosition(where, 100),
            oxygine::TweenOptions(1).delay(100).doneCallback([=](oxygine::Event*) { bla(sprite, where + 100); })
    );
}*/


void example_init ()
{
//    getStage()->setSize(640, 640);

//    oxygine::ColorRectSprite *sprite = new oxygine::ColorRectSprite;
//    sprite->setSize(100, 100);
//    sprite->setColor(0, 0, 0, 255);
//    sprite->setPosition(100, 100);
//    sprite->attachTo(oxygine::getStage());

    snake = new Game::Snake((bool *) canGo);
//    update(snake);
}

void example_update()
{
    if (firstMove)
    {

        //TODO check snake bodies in every update
//    canGo = false;
//    canGo = true;
        firstMove = false;
    }

    oxygine::sleep(100);
}

void example_destroy() {}