#include "Snake/Snake.h"


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
//    SnakeBody *snakeBody = new SnakeBody(300, 400);

//    oxygine::ColorRectSprite *sprite = new oxygine::ColorRectSprite;
//    sprite->setSize(100, 100);
//    sprite->setColor(0, 0, 0, 255);
//    sprite->setPosition(100, 100);
//    sprite->attachTo(oxygine::getStage());
//
//    bla(sprite, 100);

    Kigyo::Snake* snake = new Kigyo::Snake;

//    snakeBody->goLeft();
}

void example_update() {}

void example_destroy() {}