#include "morpion.hpp"

void afficher(Matrix mat)
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

Matrix  init()
{
	Matrix mat(3,Row(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			mat[i][j]=" ";
		}
	}
	return mat;
}

bool inserer(Matrix mat,int x,int y,string sym)
{
	if (mat[x][y]==" ")
	{
		mat[x][y]=sym;
		return true;
	}
	return false;	
}

