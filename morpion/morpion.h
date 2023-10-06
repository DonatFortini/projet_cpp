#ifndef GTKMM_MORPION_H
#define GTKMM_MORPION_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/image.h>
#include <string.h>


class Morpion : public Gtk::Window
{
public:
    Morpion(void);
    virtual ~Morpion(void);

protected:
    void on_click(Gtk::Button x);
    Gtk::Button tl, tm, tr, ml, mm, mr, bl, bm, br;
    Gtk::Grid grid;

    void casesSetup(Gtk::Button &but, int posx, int posy);
};

#endif