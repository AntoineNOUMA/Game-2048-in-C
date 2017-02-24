#include"myHeader.h"

/*!
 * Définition de la fonction jouer
 * 
 * Fonction permettant de jouer la partie en cours (on la suppose
 * initialisée)
 * Retourne 1 si la partie est terminée (l'utilisateur a gagné ou perdu),
 * et 0 sinon
 * (l'utilisateur a appuyé sur la touche Echap ou la touche s)
 */
int jouer(jeu * p)
{
    int saisie;
    int mouvement2 = 0;
    
    do  
    {
        affichage(p);
        printf("score : %d\n\n", score(p));
	saisie = saisieD();
	mouvement2 = mouvement(p, saisie);
	affichage(p);
		
        if (mouvement2 == 1) 
        {
            usleep(100000);    //pause de 0.1ms temps en nanoseconde
            ajouteValAlea(p);
	}
		
        affichage(p);
    } while (saisie != -1 && finPartie(p) == 0);

    return finPartie(p);
}

/*!
 * Définition de la fonction sauvegarde
 * 
 * Fonction sauvegardant la partie en cours 
 * Retourne 0 en cas de problème, 1 sinon.
 * 
 * \param p : pointeur sur la partie courante à sauvegarder
 */
int sauvegarde(jeu *p, char nomSauvegarde[])
{
    FILE * file = fopen(nomSauvegarde, "wt");

    if (file == NULL) 
    {
        printf("ERROR");
        return 0;
    }

    else 
    {
        int i, j;
        
        for (i = 0; i < (*p).n; i++) 
        {
            for (j = 0; j < (*p).n; j++) 
            {
                fprintf(file, "%d ", getVal(p, i, j));
            }    
            
            fprintf(file,"\n");
        }
    }
    
    fclose(file);
    return 1;
}

/*!
 * Définition de la fonction chargement
 * 
 * Fonction chargeant la dernière partie sauvegardée
 * Retourne 0 en cas de problème, 1 sinon.
 * 
 * \param p : adresse du pointeur sur le jeu
 */
int chargement(jeu *p, char nomSauvegarde[]) 
{
    FILE * file = fopen(nomSauvegarde, "rt");
    
    if (file == NULL) 
    {
        printf("ERREUR\n");
	return 0;
    }
    
    else 
    {
        int i, j, k;
        for (i=0; i < (*p).n; i++) 
        {
            for (j = 0; j < (*p).n; j++) 
            {
                fscanf(file, "%d", &k);
                setVal(p, i, j, k);
            }
        }
    }
    
    fclose(file);
    return 1;
}

/*!
 * Définition de la fonction menu
 * 
 * Affiche le menu :
 * 1 - Jouer
 * 2 - Sauvegarder
 * 3 - Charger
 * 4 - Terminer le programme
 * Retourne la valeur saisie par l'utilisateur (sasie controlée)
 */

int menu() {
	int saisie;
	do  {
		printf("     1 - Jouer\n     2 - Sauvegarder\n     3 - Charger\n     4 - Terminer le programme\n     5 - Tableau des scores\n     6 - Options\n");
		scanf("%d%*[^\n]",&saisie);
		getchar(); 					//eviter une boucle infinie si une lettre est tapée

		printf("\033[1;1H");    	//repositionne le curseur
		printf("\033[2J");			//clear
	} while (saisie < 0 || saisie > 6);

	return saisie;
}

