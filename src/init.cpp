/*v0.1*/
#include <core/oxygine.h>
#include "Snake/Snake.h"

Game::Snake* snakeBrain;
bool firstMove = true;

void example_preinit () {}

void example_init ()
{
    //TODO add snake body size to snake body as well
    snake_body_size_t snakeBodySize = {
            .width = oxygine::getStage()->getWidth() / 50,
            .height = oxygine::getStage()->getHeight() /
                      (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))
    };

    snakeBrain = new Game::Snake();
}

void example_update()
{
    if (firstMove)
    {
        firstMove = false;
        snakeBrain->start();
    }
    else
    {
        snakeBrain->check();
    }

    oxygine::sleep(100);
}

void example_destroy() {}