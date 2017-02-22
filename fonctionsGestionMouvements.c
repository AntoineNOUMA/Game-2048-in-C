#include"myHeader.h"

/*!
 * Définition de la fonction saisieD
 * 
 * Fonction permettant la saisie d'une direction ou de l'arrêt du jeu
 * (saisie répétée pour les autres touches)
 * Retourne :
 * -1 si l'utilisateur arrête le jeu
 * 0 si l'utilisateur souhaite déplacer vers le BAS
 * 1 si l'utilisateur souhaite déplacer vers la DROITE
 * 2 si l'utilisateur souhaite déplacer vers le HAUT
 * 3 si l'utilisateur souhaite déplacer vers la GAUCHE
 */
int saisieD();

/*!
 * Définition de la fonction mouvementLigne
 *  
 * Effectue les mouvements (à gauche ou à droite) des cases d'une ligne.
 * Renvoie 1 si l'on a déplacé au moins une case, 0 sinon.
 * 
 * \param p : pointeur sur un jeu
 * \param ligne : indice de ligne
 * \param direction : 1 pour déplacement vers la gauche et -1 pour
 *   un déplacement vers la droite
 */
int mouvementLigne(jeu *p, int ligne, int direction)
{
    return 0;
}

/*!
 * Définition de la fonction mouvementLignes
 *  
 * Effectue les mouvements (à gauche ou à droite) des cases sur toutes
 * les ligne.
 * Renvoie 1 si l'on a déplacé au moins une case, 0 sinon.
 * 
 * \param p : pointeur sur un jeu
 * \param direction : 1 pour déplacement vers la gauche et -1 pour un
 * déplacement vers la droite
 */
int mouvementLignes(jeu * p, int direction)
{
    return 0;
}

/*!
 * Définition de la fonction mouvementColonne
 *  
 * Effectue les mouvements (vers le haut ou vers le bas) des
 * cases d'une colonne.
 * Renvoie 1 si l'on a déplacé au moins une case, 0 sinon.
 * 
 * \param p : pointeur sur un jeu
 * \param colonne : indice de colonne
 * \param direction : -1 pour déplacement vers le bas et 1 vers le haut
 */
int mouvementColonne(jeu * p, int colonne, int direction)
{
    return 0;
}

/*!
 * Définition de la fonction mouvementColonnes
 *  
 * Effectue les mouvements (vers le haut ou vers le bas) des cases
 * de toutes les colonnes.
 * Renvoie 1 si l'on a déplacé au moins une case, 0 sinon.
 * 
 * \param p : pointeur sur un jeu
 * \param direction : -1 pour déplacement vers le bas et 1 vers le haut
 */
int mouvementColonnes(jeu * p, int colonne, int direction)
{
    return 0;
}

/*!
 * Définition de la fonction mouvement
 * 
 * \param p : pointeur sur un jeu
 * \param direction : entier donnant la direction :
 * 0 : vers le bas
 * 1 : vers la droite
 * 2 : vers le haut
 * 3 : vers la gauche
 * Renvoie 1 si l'on a déplacer au moins une case, 0 sinon 
 */
int mouvement(jeu * p, int direction);
