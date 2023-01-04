#include "morpion.hpp"

void afficher(string** mat)
{ 
	cout<<"-----------\n";   
	for (int i = 0; i < 3; i++)
	{
		cout<<"|"; 
		for (int j = 0; j < 3; j++)
		{
			cout<<"|"<<mat[i][j]<<"|";
		}
		cout<<"|\n";  
		cout<<"-----------\n";  
	}  
}

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

void jeu()
{
	bool j=true;
	while (j)
	{
		
	}
	
}