#include <emojicode/runtime/Runtime.h>
#include <gtkmm.h>

class Label : public runtime::Object<Label>, public Gtk::Label
{
};