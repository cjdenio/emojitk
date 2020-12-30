#include <emojicode/runtime/Runtime.h>
#include <emojicode/s/String.h>

#include <gtkmm.h>

class Application : public runtime::Object<Application>
{
public:
    s::String *application_id;
    Glib::RefPtr<Gtk::Application> app;
};