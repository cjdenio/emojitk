#include <gtkmm.h>
#include <emojicode/s/String.h>
#include <emojicode/runtime/Runtime.h>

#include <iostream>

class Button : public runtime::Object<Button>
{
public:
    Gtk::Button button;
};

extern "C" Button *
buttonNew(s::String *text)
{
    auto button = Button::init();

    button->button.set_label(text->stdString());

    return button;
}

SET_INFO_FOR(Button, emojitk, 23fa)

class Window : public runtime::Object<Window>
{
public:
    Gtk::Window window;
};

extern "C" Window *windowNew(s::String *title, runtime::Integer *xSize, runtime::Integer *ySize)
{
    auto window = Window::init();
    window->window.set_title(title->stdString());
    window->window.set_default_size(xSize, ySize);

    return window;
}

extern "C" void windowAdd(Window *window, Button *button)
{
    Gtk::Grid grid;

    grid.attach(button->button, 1, 1);

    grid.show_all();

    window->window.add(grid);
    grid.show();

    puts("did it");
}

SET_INFO_FOR(Window, emojitk, 1f5bc)

class Application : public runtime::Object<Application>
{
public:
    s::String *application_id;
    Glib::RefPtr<Gtk::Application> app;
};

extern "C" Application *applicationNew(s::String *id)
{
    auto app = Application::init();

    app->application_id = id;
    app->app = Gtk::Application::create(id->stdString());

    return app;
}

extern "C" void
applicationRun(Application *app, Window *window)
{
    app->app->run(window->window);
}

SET_INFO_FOR(Application, emojitk, 1f4f1)
