#ifndef SNAKE_MENUITEM_H
#define SNAKE_MENUITEM_H

#include "oxygine-framework.h"

using namespace oxygine;

namespace System
{
    class MenuItem : public Actor
    {
    public:
        explicit MenuItem(std::string label);
        MenuItem(std::string label, Resources *resources);

        void make();
    private:
        Resources* resources;
        std::string label;
        spTextField textField;

        void makeButton ();
        void makeTextField ();
    };
}


#endif //SNAKE_MENUITEM_H
