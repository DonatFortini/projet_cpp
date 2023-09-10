#include "morpion.h"
#include <iostream>

Morpion::Morpion() : m_button("")
{
    set_border_width(200);
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &Morpion::on_click));
    add(m_button);
    m_button.show();
}

Morpion::~Morpion()
{
}

void Morpion::on_click(void)
{
    std::cout<<"test 1\n";
}
