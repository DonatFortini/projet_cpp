#include "morpion.cpp"

int main(int argc, char const *argv[])
{
    string** tab=NULL;
    tab=init();
    afficher(tab);
    cout<<inserer(tab,0,2,"X")<<"\n";
    cout<<inserer(tab,1,1,"X")<<"\n";
    cout<<inserer(tab,2,0,"X")<<"\n";
    cout<<inserer(tab,2,1,"X")<<"\n";
    cout<<inserer(tab,2,2,"X")<<"\n";
    cout<<inserer(tab,2,0,"O")<<"\n";
    cout<<inserer(tab,1,2,"X")<<"\n";
    cout<<"verif\n";
    cout<<verif_diag(tab,"X")<<"\n";
    cout<<verif_colonne(tab,"X")<<"\n";
    cout<<verif_ligne(tab,"X")<<"\n";
    afficher(tab);
    free(tab);
    return 0;
}
