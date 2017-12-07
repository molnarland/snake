#include "oxygine-framework.h"

using namespace oxygine;

void example_preinit () {}

void example_init ()
{
    spSprite sprite = new ColorRectSprite;
    sprite->setPosition(300, 300);
    sprite->setSize(100, 100);
    sprite->attachTo(getStage());
}

void example_update() {}

void example_destroy() {}