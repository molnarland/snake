/*v0.1*/

#include <core/oxygine.h>
#include "Snake/Brain.h"

Game::Snake* snake;
bool firstMove = true;

void example_preinit () {}

void example_init ()
{
    snake = new Game::Snake();
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