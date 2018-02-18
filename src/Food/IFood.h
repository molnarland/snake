#ifndef SNAKE_IFOOD_H
#define SNAKE_IFOOD_H

#include "../Objects/Position.h"

using namespace GameObject;

namespace Food
{
    class IFood
    {
    public:
        virtual ~IFood (){};

        virtual void make () = 0;
        virtual void eat () = 0;

        virtual unsigned int getPont ()
        {
            return this->point;
        }

        virtual GameObject::position_t getCurrentPosition ()
        {
            return {this->positionX, this->positionY};
        }

    protected:
        const unsigned int point = 0;

        double positionX;
        double positionY;

        float width;
        float height;
    };
}
#endif //SNAKE_IFOOD_H
