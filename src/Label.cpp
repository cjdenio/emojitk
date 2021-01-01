#define [[noreturn]] __atribute__((noreturn))

#include "Label.h"
#include <emojicode/s/String.h>
#include <gtkmm.h>

extern "C" Label *labelNew(s::String *text)
{
    auto label = Label::init();
    label->set_label(text->stdString());

    return label;
}

SET_INFO_FOR(Label, emojitk, 1f9ea)
