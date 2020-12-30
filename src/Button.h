#include <emojicode/runtime/Runtime.h>
#include <gtkmm.h>

class Button : public runtime::Object<Button>, public Gtk::Button
{
};