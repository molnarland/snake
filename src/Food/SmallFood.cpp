
#include <Stage.h>
#include "SmallFood.h"

namespace Food
{
    SmallFood::SmallFood (position_t position)
    {
        this->positionX = position.x;
        this->positionY = position.y;

        this->make();
    }

    void SmallFood::make ()
    {
        this->setSize(50, 50);
        this->setColor(0, 0, 0, 255);
        this->setPosition((float) this->positionX, (float) this->positionY);
        this->attachTo(getStage());
    }

    void SmallFood::eat ()
    {
        this->detach();
    }
}