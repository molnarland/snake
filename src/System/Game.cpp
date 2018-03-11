
#include <cstdlib>
#include "Game.h"

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
    }

    void Game::start ()
    {
        this->snakeNervousSystem->start();
        this->started = true;
    }

    void Game::check ()
    {
        if (this->started)
        {
            this->snakeNervousSystem->check();
            this->foodCheck();
            
            oxygine::sleep(100);
        }
    }

    void Game::foodCheck ()
    {
        GameObject::position_t headPosition = this->snakeNervousSystem->getHead()->getPosition();
        GameObject::position_t foodPosition = food->getCurrentPosition();

        if ((int)headPosition.x == (int)foodPosition.x && (int)headPosition.y == (int)foodPosition.y)
        {
            this->addBodyToSnake();
            this->eatFood();
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

        srand(time(NULL));

        int random1 = rand() % (int)stageWidth;
        int random2 = rand() % (int)stageHeight;

        this->food = new Food::SmallFood({random1 * bodyWidth, random2 * bodyHeight}, {bodyWidth, bodyHeight});
    }


}