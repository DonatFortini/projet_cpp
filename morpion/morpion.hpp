#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

void afficher(string** mat);
string**  init();
bool inserer(string** mat,int x,int y,string sym);
bool verif_diag(string** mat,string sym);
bool verif_colonne(string** mat,string sym);
bool verif_ligne(string** mat,string sym);
void jeu();
bool verif_all(string** mat,string sym);
void gagnant(int W);
void move_com(string** mat,string sym);
