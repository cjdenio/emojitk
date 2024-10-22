#include "Window.h"
#include "Widget.h"

#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>

extern "C" Window *windowNew(s::String *title, runtime::Integer *xSize, runtime::Integer *ySize)
{
    auto window = Window::init();
    window->set_title(title->stdString());
    window->set_default_size((int)xSize, (int)ySize);

    return window;
}

extern "C" void windowAdd(Window *window, Widget *widget)
{
    window->add(*widget);
    widget->show();
}

SET_INFO_FOR(Window, emojitk, 1f5bc)
