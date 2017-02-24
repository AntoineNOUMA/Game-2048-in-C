/* 
 * File:   main.c
 * Author: Antoine NOUMA / Foyshal HOSSAIN
 *
 * Created on 23 janvier 2017, 13:17
 */

#include"myHeader.h"

/*
 * fonctionsGestionCases : OK
 * fonctionsGestionMenu : Revoir la fonction affichage avec saisieAvecEspaces
 * fonctionsGestionMouvements : Vérifier SaisieD
 * fonctoinGestionPartie : 
 * verifier les return a setVal
 */


int main() 
{
    srand (time (NULL));
    
    jeu leJeu;
    jeu *p =&leJeu;
    int n = 4;
    int valMax = 2048;
    
    initialiseJeu(p,n,valMax);
    
    printf("\033[0;0H");
    printf("\033[2J"); 

    
    int saisieMenu, slot, options, options2;
 
    
    do 
    {
        saisieMenu = menu();
        
        if (saisieMenu == 1) 
        {
            if ((*p).nbCasesLibres == ((*p).n * (*p).n)) 
            {
                ajouteValAlea(p);
                ajouteValAlea(p);
            }
            
            jouer(p);
            
            if (gagne(p) == 1) 
            {
                printf("Vous avez gagné !\n");
                
                rajouteScore(score(p));
                
                libereMemoire(p);
                
                initialiseJeu(p,n,valMax);
            }
            
            else if (perdu(p) == 1) 
            {
                printf("Vous avez perdu :/\n");
                
                rajouteScore(score(p));
                
                libereMemoire(p);
                
                initialiseJeu(p,n,valMax);
            }
	}
        
        else if (saisieMenu == 2) 
        {
            system("clear");
            
            fichierExiste("sauvegarde1.txt",1);
            
            fichierExiste("sauvegarde2.txt",2);
            
            fichierExiste("sauvegarde3.txt",3);
            
            fichierExiste("sauvegarde4.txt",4);
            
            fichierExiste("sauvegarde5.txt",5);
            
            do 
            {
                scanf("%d%*[^\n]",&slot);
                getchar();
            } while (slot < 1 || slot > 5);
            
            if (slot == 1) 
            {
                sauvegarde(p,"sauvegarde1.txt");	
            }
            
            else if (slot == 2) 
            {
                sauvegarde(p,"sauvegarde2.txt");	
            }
            
            else if (slot == 3) 
            {
                sauvegarde(p,"sauvegarde3.txt");
            }
            
            else if (slot == 4) 
            {
                sauvegarde(p,"sauvegarde4.txt");	
            }
			
            else 
            {	
                sauvegarde(p,"sauvegarde5.txt");
            }
		
            printf("Partie Sauvgardée dans le slot %d !\n", slot);
	}

	else if (saisieMenu == 3) 
        {
            system("clear");
            
            fichierExiste("sauvegarde1.txt",1);
            
            fichierExiste("sauvegarde2.txt",2);
            
            fichierExiste("sauvegarde3.txt",3);
            
            fichierExiste("sauvegarde4.txt",4);
            
            fichierExiste("sauvegarde5.txt",5);
            
            do 
            {
                scanf("%d%*[^\n]",&slot);
                
                getchar();
            } while (slot < 1 || slot > 5);

            if (slot == 1) 
            {
                chargement(p,"sauvegarde1.txt");
            }
            
            else if (slot == 2) 
            {
                chargement(p,"sauvegarde2.txt");	
            }
			
            else if (slot == 3) 
            {
                chargement(p,"sauvegarde3.txt");
            }
			
            else if (slot == 4) 
            {
                chargement(p,"sauvegarde4.txt");	
            }
		
            else 
            {
                chargement(p,"sauvegarde5.txt");
            }
            
            printf("Partie du slot %d chargée !\n", slot);
	}

	else if (saisieMenu == 5) 
        {
            tableauScore();
	}
		
	else if (saisieMenu == 6) 
        {
            system("clear");
            
            printf(" /!\\ Changer les options réinitialise la partie en cours /!\\ \n");
            
            printf(" 1 - Changer la valeur maximale (actuellement à %d) \n", (*p).valMax);
			
            printf(" 2 - Changer la dimension de la grille (actuellement %d * %d) \n",(*p).n,(*p).n);
			
            printf(" 3 - Revenir sur le menu \n");
			
            do
            {
                scanf("%d%*[^\n]",&options);

                getchar();
				
            } while (options != 1 && options != 2 && options != 3);

            if (options == 1) 
            {			
                libereMemoire(p);
				
                scanf("%d%*[^\n]",&options2);
				
                getchar();
				
                initialiseJeu(p,n,options2);
				
                (*p).valMax = options2;
				
                printf("La valeur max a été modifiée : %d\n",options2);
            }
            
            else if (options == 2) 
            {
                libereMemoire(p);
				
                scanf("%d%*[^\n]",&options2);
				
                getchar();
				
                initialiseJeu(p,options2,valMax);
				
                (*p).n = options2;
				
                printf("La dimension de la grille a été modifiée : %d\n",options2);
            }
	}

    } while (saisieMenu != 4);
    
    return EXIT_SUCCESS;
}