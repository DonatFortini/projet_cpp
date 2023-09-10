#ifndef GTKMM_MORPION_H
#define GTKMM_MORPION_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Morpion : public Gtk::Window
{
public:
    Morpion(/* args */);
    virtual ~Morpion();

protected:
    void on_click(void);

    Gtk::Button m_button;
};

#endif