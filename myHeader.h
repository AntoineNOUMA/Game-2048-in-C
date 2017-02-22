/* 
 * File:   myHeader.h
 * Author:  Antoine NOUMA / Foyshal HOSSAIN
 *
 * Created on 23 janvier 2017, 13:17
 */

#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>
#include<string.h>
#include <unistd.h>
#include<time.h>        //necesaire pour la génération de nombres aléatoire


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
  noir,
  rouge,
  vert,
  jaune,
  bleu,
  magenta,
  cyan,
  blanc
}couleur;

/*
 * Fonction effaçant le terminal
 */
void effaceTerminal();

/*
 * Printf en couleur. Les deux premiers paramètres sont les couleurs d'écriture et de fond (mettre une des valeurs parmi : 
 * BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN et WHITE).
 * Les parmètres suivants sont comme le printf "normal" : chaîne de format puis toutes les valeurs à afficher
 */
int colorPrintf(couleur fg, couleur bg, const char * format, ...);


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
int jouer(jeu * p);
int sauvegarde(jeu * p);
int chargement(jeu * p);
int menu();

//###########################################//
//### Fonctions de gestion des mouvements ###//
//###########################################//
int mouvementLigne(jeu *p, int ligne, int direction);
int mouvementLignes(jeu * p, int direction);
int mouvementColonne(jeu * p, int colonne, int direction);
int mouvementColonnes(jeu * p, int colonne, int direction);
int mouvement(jeu * p, int direction);

//########################################//
//### Fonctions de gestion de la partie###//
//########################################//
void initialiseJeu (jeu * p, int n, int valMax);
void saisieAvecEspaces(char * chaine, int n);
void affichage(jeu * p);
int gagne(jeu * p);
int perdu(jeu * p);
int finPartie (jeu * p);
