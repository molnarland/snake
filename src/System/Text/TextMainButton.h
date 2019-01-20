#ifndef SNAKE_TEXTMAINBUTTON_H
#define SNAKE_TEXTMAINBUTTON_H

#include "AbstractText.h"

namespace System
{
    namespace Text
    {
        class TextMainButton: public AbstractText
        {
        public:
            TextMainButton (const string& text, const string& resourceXmlName);

            virtual void make();
        };
    };
}

#endif //SNAKE_TEXTMAINBUTTON_H
