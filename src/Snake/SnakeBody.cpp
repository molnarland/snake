#include "oxygine-framework.h"
#include "SnakeBody.h"

SnakeBody::SnakeBody ()
{
    oxygine::spSprite sprite = new oxygine::ColorRectSprite;
    sprite->setPosition(300, 300);
    sprite->setSize(this->width, this->height);
    sprite->attachTo(oxygine::getStage());
    sprite->setColor(0, 0, 0, 255);

}