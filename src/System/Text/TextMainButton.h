#ifndef SNAKE_TEXTMAINBUTTON_H
#define SNAKE_TEXTMAINBUTTON_H

#include "AbstractText.h"

namespace System::Text
{
    class TextMainButton: public AbstractText
    {
    public:
        TextMainButton (string text, string resourceXmlName);

        virtual void make();
    };
};


#endif //SNAKE_TEXTMAINBUTTON_H
