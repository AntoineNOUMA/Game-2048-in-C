/* 
 * File:   main.c
 * Author: Antoine NOUMA / Foyshal HOSSAIN
 *
 * Created on 23 janvier 2017, 13:17
 */

#include"myHeader.h"

int main(int argc, char** argv) 
{   
    int m=menu();
 
    if(m=='1')
    {
        jeu p;

        printf("Entrez une taille de grille\n\n");
        scanf("%d", &p.n);
        while(p.n<=1)
        {
            printf("Entrez une taille de grille valide\n\n");
            scanf("%d", &p.n);
        }

        printf("\nEntrez une valeur à atteindre pour gagner\n\n");
        scanf("%d", &p.valMax);
        printf("\n\n");
        while(p.valMax<=7)
        {
            printf("Entrez une valeur à atteindre pour gagner valide\n\n");
            scanf("%d", &p.valMax);
            printf("\n\n");
        }


        initialiseJeu(&p, p.n, p.valMax);
        affichage(&p);
        sauvegarde(&p);
        libereMemoire(&p);
        sauvegarde(&p);
        
//        while(caseVide(p,i,j))
        {
          //  ajouteValAlea();
        
        }
    }
    
    if(m=='2')
    {
        jeu p;
        
        sauvegarde(&p);
        printf("menu 2");
    }
    
    if(m=='3')
    {
        jeu p;
        chargement(&p);
        printf("menu 3");
    }
    
    if(m=='4')
    {
        printf("menu 4");
    }
    
    return (EXIT_SUCCESS);
}

/*
 * fonctionsGestionCases : OK
 * fonctionsGestionMenu : Revoir la fonction affichage avec saisieAvecEspaces
 * fonctionsGestionMouvements : 
 * fonctoinGestionPartie : 
 */

/*#include <stdio.h>

int main(void)
{
    FILE *fp;
    int c;

    fp = fopen("datafile.txt", "r"); // error check this!

    // this while-statement assigns into c, and then checks against EOF:

    while((c = fgetc(fp)) != EOF) {
        
            putchar(c);
        
    }

    fclose(fp);

    return 0;
}*/