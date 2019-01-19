
#include <cstdlib>
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
        float bodySizeX = oxygine::getStage()->getWidth() / 50;
        float bodySizeY = oxygine::getStage()->getHeight() /
                          (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()));

        this->snakeNervousSystem = new Snake::SnakeNervousSystem({bodySizeX, bodySizeY});

        this->makeNewFood();
        this->makeWalls(SimpleBlackWall);
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

    void Game::makeNewFood ()
    {
        float bodyWidth = this->snakeNervousSystem->getHead()->getWidth();
        float bodyHeight = this->snakeNervousSystem->getHead()->getHeight();

        float stageWidth = oxygine::getStage()->getWidth() / bodyWidth;
        float stageHeight = oxygine::getStage()->getHeight() / bodyHeight;

        int random1 = Global::getRandom() % (int) stageWidth;
        int random2 = Global::getRandom() % (int) stageHeight;

        this->food = new Food::SmallFood({random1 * bodyWidth, random2 * bodyHeight}, {bodyWidth, bodyHeight});
    }

    void Game::makeWalls (const GameObject::WallTypes& wallType)
    {
        float bodyWidth = this->snakeNervousSystem->getHead()->getWidth();
        float bodyHeight = this->snakeNervousSystem->getHead()->getHeight();

        float stageWidth = oxygine::getStage()->getWidth() / bodyWidth;
        float stageHeight = oxygine::getStage()->getHeight() / bodyHeight;

        int random1 = Global::getRandom() % (int) stageWidth;
        int random2 = Global::getRandom() % (int) stageHeight;

        Wall::AbstractWall* wall;

        switch (wallType)
        {
            case SimpleBlackWall:
                wall = new Wall::SimpleBlackWall({random1 * bodyWidth, random2 * bodyHeight}, {bodyWidth, bodyHeight});
                break;
            default:
                throw "Invalid wall type";
        }

        wall->make();

        this->walls.push_back(wall);
    }
}