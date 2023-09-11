#ifndef GTKMM_MORPION_H
#define GTKMM_MORPION_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <string.h>



class Morpion : public Gtk::Window 
{
public:
    Morpion(/* args */);
    virtual ~Morpion();
    
protected:
    void on_click(void);
    Gtk::Button tl, tm, tr, ml, mm, mr, bl, bm, br;
    Gtk::Box grid;
    Gtk::Box row1;
    Gtk::Box row2;
    Gtk::Box row3;
    void casesSetup(Gtk::Button &but , Gtk::Box &grid);
};

#endif