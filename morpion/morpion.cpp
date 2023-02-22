#include "morpion.hpp"



string** init()
{
	string **mat =new string*[3];
	for (int i = 0; i < 3; i++)
	{
		mat[i]=new string[3];
	}

	for (int col = 0; col < 3; col++)
	{
		for (int lig = 0; lig < 3; lig++)
			{
				mat[col][lig]=".";
			}
	}
	
	return mat;
}

bool inserer(string** mat,int x,int y,string sym)
{
	return (mat[x][y]==".") ? mat[x][y]=sym,true:false;
}

bool verif_diag(string** mat,string sym)
{
	return (mat[0][0]==sym && mat[1][1]==sym && mat[2][2]==sym) ? true
	:(mat[0][2]==sym && mat[1][1]==sym && mat[2][0]==sym) ? true:false;
}

bool verif_ligne(string** mat,string sym)
{
	return (mat[0][0]==sym && mat[0][1]==sym && mat[0][2]==sym) ? true
	:(mat[1][0]==sym && mat[1][1]==sym && mat[1][2]==sym) ? true
	:(mat[2][0]==sym && mat[2][1]==sym && mat[2][2]==sym) ? true:false;
}

bool verif_colonne(string** mat,string sym)
{
	return (mat[0][0]==sym && mat[1][0]==sym && mat[2][0]==sym) ? true
	:(mat[0][1]==sym && mat[1][1]==sym && mat[2][1]==sym) ? true
	:(mat[0][2]==sym && mat[1][2]==sym && mat[2][2]==sym) ? true:false;
}

bool verif_all(string** mat,string sym)
{
	return verif_colonne(mat,sym)||verif_ligne(mat,sym)||verif_diag(mat,sym);
}

void move_com(string** mat,string sym)
{
	int randx,randy;
	do
	{
		randx=rand()%3;
		randy=rand()%3;
	} while (!inserer(mat,randx,randy,sym));
	
}


void gagnant(int W)
{
	(W==1)?cout<<"vous avez gagné\n":cout<<"l'ordi a gagné\n";
}

void jeu()
{
	bool j=true,j1=false;
	int posx,posy;
	string** mat=init();
	
	if(rand()%3==1){
		j1=true;
	}
	
	(j1) ? cout<<"premier a jouer (X)\n":cout<<"second a jouer (O)\n";
	
	while (j)
	{
		if(j1){
	
			cout<<"choissez une case (x,y)\n";
			cin>>posx>>posy;
			inserer(mat,posx,posy,"X");
			verif_all(mat,"X")?j=false,gagnant(1):move_com(mat,"O");
			verif_all(mat,"O")?j=false,gagnant(0):afficher(mat);
		}
		else{
			move_com(mat,"X");
			afficher(mat);
			if (!verif_all(mat,"X"))
			{
				cout<<"choissez une case (x,y)\n";
				cin>>posx>>posy;
				inserer(mat,posx,posy,"O");
				verif_all(mat,"O")?j=false,gagnant(1):afficher(mat);;
			}
			else gagnant(0),j=false;
		}
	}
	free(mat);
}