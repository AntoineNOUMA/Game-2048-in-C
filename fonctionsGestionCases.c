#include"myHeader.h"

/*
 * Définition de la fonction indiceValide
 * 
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon. 
 */
int indiceValide(jeu * p, int i, int j)
{
    if(i >= 0 && i < (* p).n && j >= 0 && j < (* p).n)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

/*!
 * Définition de la fonction caseVide
 *  
 * Retourne 1 si la case est vide, 0 sinon
 */
int caseVide(jeu * p, int i, int j)
{
    int x = getVal(p,i,j);
    
    if(x == 0) 
    {
        return 1;
    }
    
    else 
    {
        return 0;
    }
}

/*!
 * Définition de la fonction ajouteValAlea
 *  
 * Ajoute une valeur (2 ou 4 choisi aléatoirement) sur une case vide
 * (elle aussi choisi aléatoirement)
 */
void ajouteValAlea(jeu * p)
{
    int i;
    int j = 0;
    int nbCasesLibres = (* p).nbCasesLibres;
    int n = ((* p).n) * ((* p).n);
    
    if (nbCasesLibres > 0) 
    {
        int * tab;
	tab = (int * ) malloc(nbCasesLibres * (sizeof(int)));
        for (i = 0; i < n; i++) 
        {
            if (((* p).grille)[i] == 0) // si on a une case vide, on ajoute l'indice de la grille dans tab
            {
                tab[j] = i;		
                j++;
            }
	}
        
        int indiceAleatoire = rand() % nbCasesLibres;   //on prend une valeur aléatoire inférieure ou égale au nb de cases vides
	int indiceAleatoire2 = tab[indiceAleatoire];	// on regarde l'indice de la valeur précédente dans tab
	int valeurAleatoire;
	
        if (rand()%2 == 0) 
        {
            valeurAleatoire = 2;
	}
		
        else 
        {
            valeurAleatoire = 4;
	}

	((* p).grille)[indiceAleatoire2] = valeurAleatoire;  //on ajoute soit 2 soit 4 dans la case
        (* p).nbCasesLibres--;
    }
}

/*!
 * Définition de la fontion getVal
 *
 * Fonction retournant la valeur de la case (ligne,colonne) de la partie p
 * ou -1 si la case n'existe pas.
 * 
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
 */
int getVal(jeu * p, int ligne, int colonne)
{
    if(indiceValide(p, ligne, colonne) == 1)
    {
        int x = ((* p).n) * (ligne) + colonne;   //formule pour retrouver une case
        return((* p).grille[x]); 
    }
    
    else
    {
        return -1;
    }
}

/*!
 * Définition de la fontion setVal
 *
 * Fonction modifiant la valeur de la case (ligne,colonne) de la partie p,
 * avec la valeur val
 * 
 * Retourne 1 si le valeur de la case à été modifiée, 0 sinon. 
 * 
 * \param p : pointeur sur la partie en cours
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
 * \param val : entier à mettre dans la case (i,j) (si elle existe)
 */
int setVal(jeu * p, int ligne, int colonne, int val)
{
    if (getVal(p,ligne,colonne) == 0 && val > 0) 
    {
        ((* p).nbCasesLibres)--;	
    }
    
    else if (getVal(p,ligne,colonne) != 0 && val == 0 ) 
    {
	((* p).nbCasesLibres)++;
    }
    
    int x = ((* p).n) * (ligne) + colonne;   //formule pour retrouver une case
    
    if(indiceValide(p, ligne, colonne) == 1)
    {
        ((* p).grille[x]) = val; 
    }
}
