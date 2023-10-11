#include "morpion.h"
#include <iostream>

Morpion::Morpion(void)
{
    srand(time(0));
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

    int rands = rand() % 2;
    J1 = (rands == 1) ? true : false;
    Gtk::MessageDialog dialog((J1) ? "vous commencer premier! X" : "vous commencer deuxiemme 0", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
    dialog.run();
    if (!J1)
        comMove();
}

Morpion::~Morpion(void)
{
}

void Morpion::on_click(int posx, int posy)
{
    int val = J1;
    if (board[posy][posx] == -1)
    {
        play(posy, posx, (J1) ? "./image/X.png" : "./image/O.png", val);
        fullBoard();
        if (isWinning(val))
            finish(val);
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

void Morpion::fullBoard()
{
    bool full = true;
    for (int(&row)[3] : board)
        for (int &element : row)
            if (element == -1)
                full = false;
    if (full)
    {
        if (!isWinning(0) && !isWinning(1))
        {
            Gtk::MessageDialog dialog("ex-aequo", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
            int result = dialog.run();
            Gtk::Main::quit();
        }
    }
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

void Morpion::comMove()
{
    std::vector<std::pair<int, int>> emptyCells;
    for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
            if (board[x][y] == -1)
                emptyCells.emplace_back(x, y);

    if (!emptyCells.empty())
    {
        int val = !J1;
        std::random_shuffle(emptyCells.begin(), emptyCells.end());
        play(emptyCells[0].first, emptyCells[0].second, (J1) ? "./image/O.png" : "./image/X.png", val);
        fullBoard();
        if (isWinning(val))
            finish(val);
    }
}

void Morpion::play(int x, int y, std::string path, int player)
{
    board[x][y] = player;
    Gtk::Button *button = dynamic_cast<Gtk::Button *>(grid.get_child_at(y, x));
    Gtk::Image *pmap = Gtk::make_managed<Gtk::Image>(path);
    button->set_image(*pmap);
}
