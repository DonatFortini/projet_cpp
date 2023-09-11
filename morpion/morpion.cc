#include "morpion.h"
#include <iostream>

Morpion::Morpion() : tl("top left"), tm("top middle"), tr("top right"),
                     ml("middle left"), mm("middle middle"), mr("middle right"),
                     bl("bottom left"), bm("bottom middle"), br("bottom right")
{
    set_border_width(10);
    set_title("morpion");
    //faire des grid au final 

    add(grid);

    row1.set_orientation(Gtk::ORIENTATION_VERTICAL);
    row2.set_orientation(Gtk::ORIENTATION_VERTICAL);
    row3.set_orientation(Gtk::ORIENTATION_VERTICAL);

    grid.pack_start(row1);
    grid.pack_start(row2);
    grid.pack_start(row3);

    casesSetup(tl,row1);
    casesSetup(ml,row1);
    casesSetup(bl,row1);
    
    casesSetup(tm,row2);
    casesSetup(mm,row2);
    casesSetup(bm,row2);
    
    casesSetup(tr,row3);
    casesSetup(mr,row3);
    casesSetup(br,row3);

    row1.show();
    row2.show();
    row3.show();
    grid.show();
}

Morpion::~Morpion()
{
}

void Morpion::on_click(void)
{
    std::cout << "test 1\n";
}

void Morpion::casesSetup(Gtk::Button &but , Gtk::Box &grid)
{
    but.signal_clicked().connect(sigc::mem_fun(*this, &Morpion::on_click));
    grid.pack_start(but);
    but.show();
}