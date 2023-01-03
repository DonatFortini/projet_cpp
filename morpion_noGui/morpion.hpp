#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;

typedef vector<string> Row; 
typedef vector<Row> Matrix; 

void afficher(Matrix mat);
Matrix  init();
bool inserer(Matrix *mat,int x,int y,string sym);