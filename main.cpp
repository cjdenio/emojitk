#include <gtkmm.h>
#include <emojicode/s/String.h>

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

extern "C" void openWindow(runtime::ClassInfo *, s::String *title)
{
    auto app = Gtk::Application::create("org.gtkmm.examples.base");

    MyWindow myWindow;

    myWindow.set_title(title->stdString());

    app->run(myWindow);
}
