#include "ButtonBlack.h"

namespace System::Button
{
    ButtonBlack::ButtonBlack (const unit_size_t& size, const position_t& position) : AbstractButton(size, position)
    {}

    void ButtonBlack::make ()
    {
        this->setColor(Color(10, 10, 10));
        this->setSize(this->size.width, this->size.height);
        this->setPosition((float)this->position.x, (float)this->position.y);
    }
}