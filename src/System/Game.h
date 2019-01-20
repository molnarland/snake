#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <ox/oxygine.hpp>
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
        unit_size_t unitSize;
        std::deque<Wall::AbstractWall*> walls;

        void pushWall (position_t position);

        void addBodyToSnake ();
        void checkFood ();
        void checkWall ();
        void eatFood ();
        position_t getPosition (int x, int y);
        position_t getRandomPosition ();
        unit_size_t getStageUnitSize ();
        void makeNewFood ();
        void makeWalls (const GameObject::WallTypes& wallType);
    };
}


#endif //SNAKE_GAME_H
