/*v0.1*/
#include <core/oxygine.h>
#include "Snake/Brain.h"

Game::Snake* snakeBrain;
bool firstMove = true;

void example_preinit () {}

void example_init ()
{
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