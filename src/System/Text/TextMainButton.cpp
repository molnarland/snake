#include "TextMainButton.h"

namespace System
{
    namespace Text
    {
        TextMainButton::TextMainButton (const string& text, const string& resourceXmlName)
                : AbstractText(text, resourceXmlName)
        {}

        void TextMainButton::make ()
        {
            Resources resources;
            resources.loadXML(this->resourceXmlName);

            ResFont* font = resources.getResFont("normal");
            TextStyle style = TextStyle(font).alignMiddle();

            this->setPosition(0, 0);
            this->setSize(100, 100);
            this->setStyle(style);
            this->setText(this->text);

            resources.free();
        }
    }
}
