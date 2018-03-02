#ifndef SNAKE_ABSTRACTTEXT_H
#define SNAKE_ABSTRACTTEXT_H

#include "oxygine-framework.h"

using namespace oxygine;
using namespace std;

namespace System::Text
{
    class AbstractText : public TextField
    {
    public:
        AbstractText (string text, string resourceXmlName) : text(move(text)),
                                                             resourceXmlName(move(resourceXmlName))
        {};

        virtual void make () = 0;

    protected:
        string resourceXmlName;
        string text;
    };
}

#endif //SNAKE_ABSTRACTTEXT_H
