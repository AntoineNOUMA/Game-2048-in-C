#include"myHeader.h"

/*!
 * Définition de la fonction initialiseJeu
 * 
 * Alloue la grille de la variable jeu passée par adresse.
 * Initialise les cases de la grille avec des cases vides (valeurs nulles)
 * Initialise les champs n et valMax avec les valeurs passées en paramètre
 * 
 * \param p : pointeur sur une partie de 2048
 * \param n : taille de la grille
 * \param valMax : valeur à atteidre pour gagner
 */ 
void initialiseJeu (jeu * p, int n, int valMax)
{
    (* p).grille = (int *) malloc((n * n) * (sizeof(int)));  //allocation dynamique de la grille
    
    int * i;
    
    for (i = (* p).grille; i < (* p).grille+(n * n); i++) 
    {
        * i = 0;                                   // initialise toutes les cases de la grille à 0
    }
    
    (* p).n = n;                                   
    (* p).valMax = valMax;                         
    (* p).nbCasesLibres = (n * n);
}


void libereMemoire(jeu * p) 
{
    free ((*p).grille); // On n'a plus besoin de la mémoire, on la libère
    (*p).grille = NULL;
}

/*!
 * Définition de la fonction gagne
 *  
 * Retourne 1 si la partie est gagnée, 0 sinon
 */
int gagne(jeu * p)
{
    int i, j;
    
    for (i = 0; i < (* p).n; i++) 
    {
        for (j = 0; j < (* p).n; j++) 
        {
            if (getVal(p,i,j) >= (*p).valMax) 
            {
                return 1;
            }
	}
    }
    
    return 0;

}

/*!
 * Définition de la fonction perdu
 *  
 * Retourne 1 si la partie est perdue, 0 sinon
 */
int perdu(jeu * p)
{
    if ((* p).nbCasesLibres == 0) 
    {
        int i;
        int j;
        
        for (i = 0; i < (* p).n; i++) 
        {
            for (j = 0; j < (*p).n; j++) 
            {
                if (getVal(p,i,j) == getVal(p,i+1,j) || getVal(p,i,j) == getVal(p,i,j+1)) 
                {
                    return 0;																// si case a coté contient le mm numéro pas perdu
		}
            }
        }
        
        return 1;
    }
    
    return 0;
}
    

/*!
 * Définition de la fonction finPartie
 *  
 * Retourne 1 si la partie est terminée, 0 sinon
 */
int finPartie (jeu * p)
{
    if(perdu(p) || gagne(p))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int score(jeu *p) 
{
    int i, j;
    int score = 0;
    
    for (i=0; i < (* p).n; i++) 
    {
        for (j = 0; j < (*p).n; j++) 
        {
            score = score + getVal(p,i,j);		//somme de toutes les cases
	}
    }
	
    return score;
}

void fichierExiste(char nomFichier[], int slot) {
	if (fopen(nomFichier,"r") != NULL) {
		printf("slot %d : OCCUPEE\n",slot);
	}
	else {
		printf("slot %d : VIDE\n",slot);
	}
}

void rangerTab(int tab[], int taille) {
	int i,i2,val,val2,indiceVal;
	val = tab[0];
	indiceVal = 0;

	for (i=0;i<taille;i++) {
		for (i2=i;i2<taille;i2++) {
			if (val < tab[i2]) {
				val = tab[i2];
				indiceVal = i2;
			}
		}
		val2 = tab[i];
		tab[i] = val;
		tab[indiceVal] = val2;
		val = -1;
	}
}

void tableauScore() {
	int i;
	int tabScore[10];
	for (i=0; i<10;i++) {
		tabScore[i] = 0;
	}
	FILE *file = fopen("score.txt","rt");

	if (file == NULL) {
		printf("Nothing ^-^\n");
	}

	else {
		for (i=0;i<10 && !feof(file); i++) {
			fscanf(file,"%d",&(tabScore[i]));
		}

		rangerTab(tabScore,10);

		for (i=0;i<10;i++) {
			printf("%2d  - %d\n",i+1,tabScore[i]);
		}
		fclose(file);
	}
}

void rajouteScore(int score) {
	int i,x;
	FILE *file;
	file = fopen("score.txt","at");
	file = fopen("score.txt","rt");

	for (i=0; !feof(file); i++)
	{
		fscanf(file,"%d",&x);
	}

	if (i > 9) {
		file = fopen("score.txt","rt");
		int tab[10];	
		for (i=0;!feof(file);i++) {
			fscanf(file,"%d",&(tab[i]));
		}
		rangerTab(tab,10);
		tab[9] = score;
		rangerTab(tab,10);

		file = fopen("score.txt","wt");
		for (i=0;i<10;i++) {
			fprintf(file,"%d\n",tab[i]);
		}
	}
	else {
		file = fopen("score.txt","at");
		fprintf(file,"%d\n",score);
	}

	fclose(file);
}