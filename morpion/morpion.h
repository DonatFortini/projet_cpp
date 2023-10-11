#ifndef GTKMM_MORPION_H
#define GTKMM_MORPION_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/image.h>
#include <gtkmm.h>

#include <string.h>
#include <cstdlib>

class Morpion : public Gtk::Window
{
public:
    Morpion(void);
    virtual ~Morpion(void);

protected:
    void on_click(int posx, int posy);
    void casesSetup(Gtk::Button &but, int posx, int posy);
    bool verifRow(int val);
    bool verifCol(int val);
    bool verifDiag(int val);
    bool isWinning(int val);
    void fullBoard();
    void finish(int val);
    void printBoard();
    void comMove();
    void play(int x, int y, std::string path, int player);
    Gtk::Button tl, tm, tr, ml, mm, mr, bl, bm, br;
    Gtk::Grid grid;
    bool J1;
    int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
};

#endif