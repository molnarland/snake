//
// Created by molnarland on 2/18/18.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <core/oxygine.h>
#include "../Snake/SnakeNervousSystem.h"
#include "../Food/SmallFood.h"
#include "../Wall/AbstractWall.h"
#include "../Objects/WallTypes.h"

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
        void finish ();

        bool started = false;
        bool finished = false;
    private:
        SnakeNervousSystem* snakeNervousSystem;
        IFood* food;
        std::deque<Wall::AbstractWall*> walls;

        void checkFood ();
        void checkWall ();
        void addBodyToSnake ();
        void eatFood ();
        void makeNewFood ();
        void makeWalls (const GameObject::WallTypes& wallType);
    };
}


#endif //SNAKE_GAME_H
