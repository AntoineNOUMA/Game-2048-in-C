#include"myHeader.h"

/*
 * Définition de la fonction indiceValide
 * 
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon. 
 */
int indiceValide(jeu * p, int i, int j)
{
    if(i>=0 && i<(*p).n && j>=0 && j<(*p).n)
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
    if(getVal(p,i,j)==0) 
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
    if((*p).nbCasesLibres>=1)
    {
	srand(time(NULL));
    	int j=rand()%(2);
	int k=rand()%(p->n*p->n);
        
	if(j==0)	
        {
            (*p).grille[k]=2;
        }
    	else 		
        {
            (*p).grille[k]=4;
        }
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
    if(indiceValide(p, ligne, colonne)==1)
    {
        return((*p).grille[((*p).n)*(ligne)+colonne]);
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
    if(getVal(p, ligne, colonne)!=-1)
    {
        ((*p).grille[((*p).n)*(ligne)+colonne])=val;
        return 1;
    }
    else
    {
        return 0;
    }
}
