#include <gtkmm.h>
#include <emojicode/s/String.h>
#include <iostream>

// BEGIN TESTING STUFF
class MyWindow : public Gtk::Window
{
public:
    MyWindow();
};

MyWindow::MyWindow()
{
    set_title("Basic application");
    set_default_size(200, 200);
}
// END TESTING STUFF

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
applicationRun(Application *app)
{
    // MyWindow myWindow;
    // app->app->run(myWindow);
}

SET_INFO_FOR(Application, emojitk, 1f4f1)

extern "C" void openWindow(runtime::ClassInfo *, s::String *title)
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    MyWindow myWindow;

    myWindow.set_title(title->stdString());

    app->run(myWindow);
}
