/* 
 * File:   myHeader.h
 * Author:  Antoine NOUMA / Foyshal HOSSAIN
 *
 * Created on 23 janvier 2017, 13:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <math.h>
#include <time.h>        //necesaire pour la génération de nombres aléatoire


/*Définition du type structuré jeu
 *
 * Le pointeur grille contiendra l'adresse d'un tableau à une dimension alloué dynamiquement.
 * Ce tableau représentera la grille du jeu.
 * Les lignes seront sodées les unes à la suite des autres.
 * Les n premières cases du tableau grille représenterons la première ligne de la grille.
 * Les n suivantes  la deuxième ligne
 * ect...
 * Chaque case de ce tableau contiendra la valeur de la case
 * 0 si la case esr vide
 */
typedef struct
{
    int n;              //taille de la grille (n*n)
    int valMax;         //valeur à atteindre pour gagner
    int nbCasesLibres;  //nombre de cases libres sur la grille
    int * grille;       //pointeur d'entier permettant de stocker l'adresse de la grille allouée dynamiquement
}jeu;

/*Définition du type énuméré couleur
 *
 * Permet de colorer le terminal
 */
typedef enum
  {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
  } couleur;
  
 /*Définition du type énuméré touche
  * 
  * Touches du clavier correspondant aux flèches (haut, bas, gauche, droite) + touche echap + autres touches
  */ 
typedef enum
{
	NO_KEY,
	KEY_ESCAPE,
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT
} toucheFleche;

//########################################//
//### Fonctions de gestion du terminal ###//
//########################################//
void clear_terminal();
int color_printf(couleur fg, couleur bg, const char * format, ...);
couleur couleurNombre(int x);
void affichageLigne(int x);
void affichage(jeu * p);
int debutTerminalSansR();
void finTerminalSansR();

//######################################//
//### Fonctions de gestion des cases ###//
//######################################//
int indiceValide(jeu * p, int i, int j);
int caseVide(jeu * p, int i, int j);
void ajouteValAlea(jeu * p);
int getVal(jeu * p, int ligne, int colonne);
int setVal(jeu * p, int ligne, int colonne, int val);

//###################################//
//### Fonctions de gestion du menu###//
//###################################//
int menu();
int jouer(jeu * p);
int sauvegarde(jeu * p, char nomSauvegarde[]);
int chargement(jeu * p, char nomSauvegarde[]);
void tableauScore();

//###########################################//
//### Fonctions de gestion des mouvements ###//
//###########################################//
int fusionGauche(jeu *p,int ligne);
int fusionDroite(jeu *p,int ligne);
int fusionBasse(jeu *p,int ligne);
int fusionHaute(jeu *p,int ligne);
int tassageGauche(jeu *p,int ligne);
int tassageDroit(jeu *p,int ligne);
int tassageHaut(jeu *p,int ligne);
int tassageBas(jeu *p,int ligne);
int mouvementLigne(jeu *p, int ligne, int direction);
int mouvementLignes(jeu * p, int direction);
int mouvementColonne(jeu * p, int colonne, int direction);
int mouvementColonnes(jeu * p, int direction);
int mouvement(jeu * p, int direction);
toucheFleche lectureFleche();

//########################################//
//### Fonctions de gestion de la partie###//
//########################################//
void initialiseJeu (jeu * p, int n, int valMax);
int tailleNombre(int x);
int score(jeu *p);
void rajouteScore(int score);
int gagne(jeu * p);
int perdu(jeu * p);
void libereMemoire(jeu * p);
void rangerTab(int tab[], int taille);
void fichierExiste(char nomFichier[], int slot);
int finPartie (jeu * p);