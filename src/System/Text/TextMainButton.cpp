#include "TextMainButton.h"

namespace System::Text
{
    TextMainButton::TextMainButton (string text, string resourceXmlName)
            : AbstractText(text, resourceXmlName)
    {}

    void TextMainButton::make ()
    {
        Resources resources;
        //TODO got segmentation fault 
        bool loaded = resources.loadXML(this->resourceXmlName);

        log::messageln("%d", loaded);

        if (loaded)
        {

            ResFont* font = resources.getResFont("main");
            TextStyle style = TextStyle(font).alignMiddle();


            this->setPosition(0, 0);
            this->setSize(100, 100);
            this->setStyle(style);
            this->setText(this->text);
        }

        resources.free();
    }
}
