#include <emojicode/runtime/Runtime.h>
#include <gtkmm.h>

class Widget : public runtime::Object<Widget>, public Gtk::Widget
{
};