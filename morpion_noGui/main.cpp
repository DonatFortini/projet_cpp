#include "morpion.cpp"

int main(int argc, char const *argv[])
{
    Matrix tab;
    tab=init();
    afficher(tab);
    cout<<inserer(tab,0,0,"X")<<"\n";
    afficher(tab);
    return 0;
}
