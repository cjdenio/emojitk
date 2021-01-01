#define [[noreturn]] __atribute__((noreturn))

#include "Application.h"
#include "Window.h"

#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>

#include <gtkmm.h>

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
    app->app->run(*window);
}

SET_INFO_FOR(Application, emojitk, 1f4f1)
