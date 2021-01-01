#include "Button.h"

#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>

extern "C" Button *
buttonNew(s::String *text)
{
    auto button = Button::init();

    button->set_label(text->stdString());

    return button;
}

SET_INFO_FOR(Button, emojitk, 23fa)