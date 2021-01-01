#include <emojicode/runtime/Runtime.h>

#include "Widget.h"

extern "C" Widget *widgetNew()
{
    return Widget::init();
}

SET_INFO_FOR(Widget, emojitk, 1f4ec)