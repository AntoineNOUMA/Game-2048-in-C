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
    while(valMax%2!=0)
    {
        printf("################################\n");
        printf("##Entrez une puissance de deux##\n");
        printf("################################\n\n");
        scanf("%d", &valMax);
    }
        valMax=valMax/2;
    
    (*p).grille=malloc(sizeof(int)*(n*n));          // alloue la mémoire dynamiquement pour n*n entiers
    
    if ((*p).grille == NULL)                        // On vérifie si la mémoire a été allouée
    {
        printf("La mémoire n'a pas été allouée");
       // exit(0);                                    // Erreur : on arrête tout !
    }

    int i=0;
    
    while(i<n*n)
    {
        (*p).grille[i]=0;
        i++;
    }
    
    srand(time(NULL));

    int j=rand()%(n*n);
    int k=rand()%(n*n);
    (*p).grille[j]=2;
    (*p).grille[k]=4;         //voir si le nombre change en fonction de la taille de la grille ex 2048->4096
}

void libereMemoire(jeu * p) 
{   
    int i=0;

    while(i<((*p).n)*((*p).n))
    {
        free ((*p).grille); // On n'a plus besoin de la mémoire, on la libère
        i++;
        (*p).grille++;
    }
}



/*!
 * Définition de la fonction SasieAvecEspaces
 * 
 * Fonction permettant de lire les caractères saisis au clavier.
 * La fonction permet de lire même les espaces. La lecture s'arrête au 
 * caractère saut de ligne ('\n'). Les caractères lus sont stockés dans
 * le paramètre chaine.
 * 
 * Remarque : pour éviter des dépassements de tableaux, la fonction lit 
 * au plus n caractères. Les caractères restants (jusqu'au saut de ligne)
 * sont supprimés.
 */
void purger()
{
  int c;
  while ((c = getc(stdin)) != '\n' && c != EOF);
}

void clean (char *chaine)
{
   char *p = strchr(chaine, '\n');
   if (p)
    *p = 0;
   else
    purger();
}

void saisieAvecEspaces(char * chaine, int n)
{
    fgets(chaine, n, stdin);
    clean(chaine);
}

/*
Exemple d'utilisation de la fonction saisie_avec_espaces.
int main()
{
	char ch1[5];
	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

	printf("Tapez une phrase : \n");
	saisie_avec_espaces(ch1,5);
	printf("Vous avez tape : '%s'\n", ch1);

    return 0;
}
*/

/*!
 * Définition de la fontion affichage
 *
 * Fonction affichant la grille à l'écran.
 * 
 * \param p : pointeur sur la partie que l'on souhaite afficher
 */
void affichage(jeu * p)
{
    int i=0;
    
    while(i<((*p).n)*((*p).n))
    {
        printf("%d",(*p).grille[i]);
        printf("\t");
        i++;
        
        if(i%(*p).n==0)
        {
            printf("\n\n\n");
        }
    }           
}


/*!
 * Définition de la fonction gagne
 *  
 * Retourne 1 si la partie est gagnée, 0 sinon
 */
int gagne(jeu * p)
{
    int i=0;

    while(i<((*p).n)*((*p).n))
    {
	if((*p).grille[i]==(*p).valMax) 
        {
            return 1;
        }
	else 
        {
            return 0;
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
    if ((*p).nbCasesLibres==0) //Il n'y a plus de cases libres.
    {
        int count=0; //Compteur qui permettra de déterminer quand est-ce qu'on a perdu
        int i=0; //Compteur pour le parcours du tableau
        int j=0;
        
        while(i<((*p).n*(*p).n)) //Itération jusqu'à la valeur de l'avant dernière case qui est à vérifier avec la dernière valeur
        {
            if(i%(*p).n!=((*p).n)-1) //Condition au cas ou˘ on arrive à la fin d'une ligne.
            {
                if (getVal(p,i,j)==getVal(p,i,j+1))
                {
                    return 0; //Si les cases de droite et de gauche d'une ligne sont égales, le jeu n'est pas fini.
                }
                else
                {
                    i++; //Si les cases de droite et de gauche d'une ligne sont différentes, on passe à la prochaine case.
                    count++; //Compteur permettant de déterminer quand est-ce qu'on a perdu.
                    
                    if(count==(*p).n*(((*p).n)-1))/* On a vérifie sur toutes les cases de droite et de gauche du tableau il faut maintenant vérifier toutes les du haut et du bas de chaque colonne.*/        
                    {
                        i=0; //On va à nouveau parcourir le tableau
                        
                        while(i<((*p).n*(*p).n-(*p).n)) //Itération jusqu'à la dernière case de l'avant dernière ligne du tableau
                        {
                            if(getVal(p,i,j)==getVal(p,i+1,j))
                            {
                                return 0; //Si les cases du haut et du bas d'une colonne sont égales, le jeu n'est pas fini.
                            }
                            else
                            {
                                i++; //Si les cases du haut et du bas d'une colonne sont differentes, on passe à la colonne à côté.
                                count++; //Compteur permettant de dÈterminer quand est-ce qu'on a perdu.
                                
                                if(count==(*p).n*((*p).n-1)+(*p).n*((*p).n-1))
                                {
                                    return 1;
                                }
                                    /* Lorsqu'on a fait toutes les combinaisons pour vÈrifier s'il y a deux cases
                                       Ègales sur toutes les lignes et sur toutes les colonnes, alors on a perdu. */
                                else
                                {
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                i++; //Si on arrive en fin de ligne, de la boucle pour les vérifications dans les lignes, on passe à la ligne suivante.
            }
        }
    }
    else
    {
        return 1; //Il reste au moins une case vide, le jeu n'est donc pas fini.
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
