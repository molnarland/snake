
#include <ox/Stage.hpp>
#include "SmallFood.h"

namespace Food
{
    SmallFood::SmallFood (position_t position, unit_size_t size)
    {
        this->positionX = position.x;
        this->positionY = position.y;

        this->width = size.width;
        this->height = size.height;

        this->make();
    }

    void SmallFood::make ()
    {
        this->setSize(this->width, this->height);
        this->setColor(0, 0, 0, 255);
        this->setPosition((float) this->positionX, (float) this->positionY);
        this->attachTo(getStage());
    }

    void SmallFood::eat ()
    {
        this->detach();
    }
}
