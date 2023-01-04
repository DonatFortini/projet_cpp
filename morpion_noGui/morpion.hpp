#include <iostream>
#include <string>

using std::cout;
using std::string;

void afficher(string** mat);
string**  init();
bool inserer(string** mat,int x,int y,string sym);
bool verif_diag(string** mat,string sym);
bool verif_colonne(string** mat,string sym);
bool verif_ligne(string** mat,string sym);
void jeu();