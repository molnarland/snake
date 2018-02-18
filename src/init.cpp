/*v0.1*/
#include <core/oxygine.h>
#include "Snake/SnakeNervousSystem.h"

Snake::SnakeNervousSystem* snake;
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

    snake = new Snake::SnakeNervousSystem(
            {oxygine::getStage()->getWidth() / 50,
             oxygine::getStage()->getHeight() / (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))
            });
}

void example_update()
{
    if (firstMove)
    {
        firstMove = false;
        snake->start();
    }
    else
    {
        snake->check();
    }

    oxygine::sleep(100);
}

void example_destroy() {}