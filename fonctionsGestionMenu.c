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
/*int menu()
{
  char choixMenu;
  
  do
  { 
      printf("========== Menu ==========\n\n");
      printf("1 - Jouer\n");
      printf("2 - Sauvegarder\n");
      printf("3 - Charger\n");
      printf("4 - Terminer le programme\n\n");
      printf("Quel est votre choix ? \n\n");
      scanf("%c", &choixMenu);
      printf("\n");
  
  switch (choixMenu)
  {
    case '1':
       printf("Vous avez choisi de jouer.\n\n");
       return (choixMenu);
       break;
    case '2':
       printf("Vous avez choisi de sauvegarder.\n\n");
       return (choixMenu);
       break;
    case '3':
         printf("Vous avez choisi de charger.\n\n");
         return (choixMenu);
         break;
    case '4':
       printf("Vous avez choisi de terminer le programme.\n\n");
       return (choixMenu);
       break;
    default:
        printf("######################################\n");
        printf("##Veuillez saisir un nombre correct.##\n");
        printf("######################################\n\n");
        //return (choixMenu);
        break;
   }
  
  }while (choixMenu<1 || choixMenu>4);
  system("pause");
 
  return 0;
}*/
