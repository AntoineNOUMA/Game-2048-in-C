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
    if (gagne(p) || perdu(p))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

/*!
 * Définition de la fonction sauvegarde
 * 
 * Fonction sauvegardant la partie en cours 
 * Retourne 0 en cas de problème, 1 sinon.
 * 
 * \param p : pointeur sur la partie courante à sauvegarder
 */
int sauvegarde(jeu * p)
{
    int * sauvegardeGrille;
    int i=0;
    while(i<((*p).n)*((*p).n))
    {
        sauvegardeGrille=(*p).grille;
        printf("%d",*sauvegardeGrille);
        printf("\t");
        i++;
        (*p).grille++;
        
        if(i%(*p).n==0)
        {
            printf("\n\n\n");
        }   
        
        
    }   
    return 0;
}

/*!
 * Définition de la fonction chargement
 * 
 * Fonction chargeant la dernière partie sauvegardée
 * Retourne 0 en cas de problème, 1 sinon.
 * 
 * \param p : adresse du pointeur sur le jeu
 */
int chargement(jeu * p)
{
    return 0;
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
int menu()
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
}
