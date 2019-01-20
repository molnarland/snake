
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "../Wall/SimpleBlackWall.h"
#include "../Global/Percentage.h"
#include "../Global/getRandom.h"

namespace System
{
    Game::Game ()
    {

    }

    void Game::make ()
    {
        float bodySizeX = oxygine::getStage()->getWidth() / 64;
        float bodySizeY = oxygine::getStage()->getHeight() /
                          (96 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()));
        this->unitSize = {bodySizeX, bodySizeY};

        this->snakeNervousSystem = new Snake::SnakeNervousSystem(this->unitSize);

        this->makeNewFood();
        this->makeWalls(Cube, SimpleBlackWall);
    }

    void Game::start ()
    {
        this->snakeNervousSystem->start();
        this->started = true;
    }

    void Game::check ()
    {
        if (this->started && !this->finished)
        {
            this->snakeNervousSystem->check();
            this->checkFood();
            this->checkWall();

            oxygine::sleep(100);
        }
    }

    void Game::finish ()
    {
        this->finished = true;
//        this->snakeNervousSystem->
    }

    void Game::checkFood ()
    {
        GameObject::position_t headPosition = this->snakeNervousSystem->getHead()->getPosition();
        GameObject::position_t foodPosition = food->getCurrentPosition();

        if ((int)headPosition.x == (int)foodPosition.x && (int)headPosition.y == (int)foodPosition.y)
        {
            this->addBodyToSnake();
            this->eatFood();
        }
    }

    void Game::checkWall ()
    {
        GameObject::position_t headPosition = this->snakeNervousSystem->getHead()->getPosition();
        size_t wallsLength = this->walls.size();
        unsigned int index = 0;

        while (index < wallsLength && !this->finished)
        {
            GameObject::position_t wallPosition = this->walls[index]->getPosition();

            if ((int)headPosition.x == (int)wallPosition.x && (int)headPosition.y == (int)wallPosition.y)
            {
                this->finish();
            }

            index++;
        }
    }

    void Game::addBodyToSnake ()
    {
        this->snakeNervousSystem->grow();
    }

    void Game::eatFood ()
    {
        this->food->eat();
        this->makeNewFood();
    }

    position_t Game::getPosition (int x, int y)
    {
        float unitWidth = this->unitSize.width;
        float unitHeight = this->unitSize.height;

        return {(float) x * unitWidth, (float) y * unitHeight};
    }

    position_t Game::getRandomPosition ()
    {
        unit_size_t stageSize = this->getStageUnitSize();
        
        return this->getPosition(
            Global::getRandom(0, (int) stageSize.width), 
            Global::getRandom(0, (int) stageSize.height)
        );
    }

    unit_size_t Game::getStageUnitSize ()
    {
        return {
            oxygine::getStage()->getWidth() / this->unitSize.width, 
            oxygine::getStage()->getHeight() / this->unitSize.height
        };
    }

    void Game::makeNewFood ()
    {
        this->food = new Food::SmallFood(this->getRandomPosition(), this->unitSize);
    }

    void Game::pushWall (position_t position)
    {
        this->walls.push_back(new Wall::SimpleBlackWall(position, this->unitSize));
    }

    void Game::makeWalls (const GameObject::Levels& level, const GameObject::WallTypes& wallType)
    {
        switch (wallType)
        {
            case SimpleBlackWall:
                { 
                    unit_size_t stageSize = this->getStageUnitSize();       

                    for (int index = 0; index < stageSize.width; index++)
                    {
                        this->pushWall({this->unitSize.width * index, 0});
                        this->pushWall({this->unitSize.width * index, stageSize.height * this->unitSize.height - this->unitSize.height});
                    } 

                    for (int index = 0; index < stageSize.height; index++)
                    {
                        this->pushWall({0, this->unitSize.height * index});
                        this->pushWall({stageSize.width * this->unitSize.width - this->unitSize.width, this->unitSize.height * index});
                    }
                }
                break;
            default:
                throw "Invalid wall type";
        }

        for (int index = 0; index < this->walls.size(); index++)
        {
            this->walls[index]->make();
        }
    }
}
