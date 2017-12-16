#include "Brain.h"

namespace Game {
    Brain::Brain () : Snake({oxygine::getStage()->getWidth() / 50,
                     oxygine::getStage()->getHeight()
                     / (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))})
    {

    }

    void Brain::check ()
    {

    }
}