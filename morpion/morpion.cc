#include "morpion.h"
#include <iostream>

Morpion::Morpion(void) 
{
    set_border_width(10);
    set_title("morpion");
    grid.set_hexpand(true);
    grid.set_vexpand(true);
    grid.set_row_homogeneous(true);
    grid.set_column_homogeneous(true);

    add(grid);

    casesSetup(tl, 0, 0);
    casesSetup(tm, 0, 1);
    casesSetup(tr, 0, 2);

    casesSetup(ml, 1, 0);
    casesSetup(mm, 1, 1);
    casesSetup(mr, 1, 2);

    casesSetup(bl, 2, 0);
    casesSetup(bm, 2, 1);
    casesSetup(br, 2, 2);

    grid.show();
}

Morpion::~Morpion(void)
{
}

void Morpion::on_click(Gtk::Button x)
{
    
}

void Morpion::casesSetup(Gtk::Button &but, int posx, int posy)
{
    but.signal_clicked().connect(sigc::mem_fun(*this, &Morpion::on_click));
    auto pmap = Gtk::make_managed<Gtk::Image>("./image/Empty.png");
    but.set_image(*pmap);
    grid.attach(but, posx, posy);
    but.show();
}