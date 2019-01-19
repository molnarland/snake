//
// Created by molnarland on 2/18/18.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ox/oxygine.hpp>
#include "../Snake/SnakeNervousSystem.h"
#include "../Food/SmallFood.h"

using namespace Snake;
using namespace Food;

namespace System
{
    class Game
    {
    public:
        Game ();
        void make ();
        void start ();
        void check ();

        bool started = false;
    private:
        SnakeNervousSystem* snakeNervousSystem;
        IFood* food;

        void foodCheck ();
        void addBodyToSnake ();
        void eatFood ();
        void makeNewFood ();
    };
}


#endif //SNAKE_GAME_H
