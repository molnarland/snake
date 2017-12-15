#ifndef SNAKE_CONSTS_H
#define SNAKE_CONSTS_H

#include "Objects/Size.h"

namespace Constants
{
    snake_body_size_t snakeBodySize = {
            .width = oxygine::getStage()->getWidth() / 50,
            .height = oxygine::getStage()->getHeight() /
                    (50 / (oxygine::getStage()->getWidth() / oxygine::getStage()->getHeight()))
    };
};

#endif //SNAKE_CONSTS_H