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

void Morpion::on_click(int posx, int posy)
{
    if (board[posy][posx] == -1)
    {
        play(posy, posx, "./image/X.png", 1);
        if (isWinning(1))
            finish(1);
        comMove();
    }
}

void Morpion::casesSetup(Gtk::Button &but, int posx, int posy)
{
    but.signal_clicked().connect([=]()
                                 { on_click(posx, posy); });
    Gtk::Image *pmap = Gtk::make_managed<Gtk::Image>("./image/Empty.png");
    but.set_image(*pmap);
    grid.attach(but, posx, posy);
    but.show();
}

bool Morpion::verifRow(int val)
{
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == val && board[i][1] == val && board[i][2] == val)
            return true;
    return false;
}

bool Morpion::verifCol(int val)
{
    for (int i = 0; i < 3; ++i)
        if (board[0][i] == val && board[1][i] == val && board[2][i] == val)
            return true;
    return false;
}

bool Morpion::verifDiag(int val)
{
    return (board[0][0] == val && board[1][1] == val && board[2][2] == val) || (board[0][2] == val && board[1][1] == val && board[2][0] == val);
}

bool Morpion::isWinning(int val)
{
    return verifCol(val) || verifRow(val) || verifDiag(val);
}

void Morpion::finish(int val)
{
    Gtk::MessageDialog dialog("Joueur " + std::to_string(val) + " à gagner", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
    int result = dialog.run();
    Gtk::Main::quit();
}

void Morpion::printBoard()
{
    for (int(&row)[3] : board)
    {
        for (int &element : row)
            std::cout << element << " ";
        std::cout << std::endl;
    }
}

bool Morpion::comMove()
{
    std::vector<std::pair<int, int>> emptyCells;
    for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
            if (board[x][y] == -1)
                emptyCells.emplace_back(x, y);

    if (!emptyCells.empty())
    {
        std::random_shuffle(emptyCells.begin(), emptyCells.end());
        play(emptyCells[0].first, emptyCells[0].second, "./image/O.png", 0);
        if (isWinning(0))
            finish(0);
        return true;
    }
    return false;
}

void Morpion::play(int x, int y, std::string path, int player)
{
    board[x][y] = player;
    Gtk::Button *button = dynamic_cast<Gtk::Button *>(grid.get_child_at(y, x));
    Gtk::Image *pmap = Gtk::make_managed<Gtk::Image>(path);
    button->set_image(*pmap);
}
