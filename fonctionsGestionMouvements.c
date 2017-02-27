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
int saisieD() 
{
    debutTerminalSansR();
    
    toucheFleche saisie = NO_KEY;
	
    do  
    {
        saisie = lectureFleche();	
    } while (saisie == NO_KEY);

    if (saisie == KEY_DOWN) 
    {
        finTerminalSansR();
	return 0;
    }
	
    else if (saisie == KEY_RIGHT) 
    {
        finTerminalSansR();
        return 1;
    }
	
    else if (saisie == KEY_UP) 
    {
        finTerminalSansR();
	return 2;
    }
	
    else if (saisie == KEY_LEFT) 
    {
        finTerminalSansR();
        return 3;
    }
	
    else 
    {
        finTerminalSansR();
	return -1;
    }
}


int fusionGauche(jeu *p, int ligne) 
{
    int i, j;
    int k = 0;
    int val = 0;
    int val2 = 0;

    for (i = 0; i < (*p).n; i++) 
    {
        if (getVal(p, ligne, i) != 0) 
        {
            val = getVal(p, ligne, i);				//on recup la valeur si non nulle
			
            for (j = i+1; j < (*p).n; j++) 
            {
                if (getVal(p, ligne, j) != 0) 
                {
                    val2 = getVal(p, ligne, j);  //on recupère la valeur de droite
                    break;
                }
            }
            
            if (val == val2) 
            {
                setVal(p, ligne, i, val + val2); // on les fusionne
                setVal(p, ligne, j, 0);		 // on supprime la case de droite
                k++;
            }
		
            val = 0;
            val2 = 0;
        }
    }
        if (k > 0) 
        {
            return 1;         //s'il y a eu fusion retourne 1
	}

	else 
        {
		return 0;
	}
}

int fusionDroite(jeu *p, int ligne) 
{
    int i, j;
    int k = 0;
    int val = 0;
    int val2 = 0;

    for (i=(*p).n; i >= 0; i--) 
    {
        if (getVal(p, ligne, i) != 0) 
        {
            val = getVal(p, ligne, i);
	
            for (j = i-1; j >= 0; j--) 
            {
                if (getVal(p, ligne, j) != 0) 
                {
                    val2 = getVal(p, ligne, j);
                    break;
		}
            }
            
            if (val == val2) 
            {
                setVal(p, ligne, i, val * 2);
		setVal(p,ligne, j, 0);
		k++;
            }
            
            val = 0;
            val2 = 0;
	}
    }

    if (k > 0) 
    {
        return 1;
    }
	
    else 
    {
	return 0;
    }
}

int fusionHaute(jeu *p, int colonne) 
{
    int i, j;
    int k = 0;
    int val = 0;
    int val2 = 0;

	for (i = 0; i < (*p).n; i++) 
        {
            if (getVal(p, i, colonne)!= 0) 
            {
                val = getVal(p, i, colonne);
		
                for (j=i+1; j < (*p).n; j++) 
                {
                    if (getVal(p, j, colonne) != 0) 
                    {
                        val2 = getVal(p, j, colonne);
			break;
                    }
		}	
		
                //printf("val = %d\n val2 = %d\n",val,val2);
                
		if (val == val2) 
                {
                    setVal(p, i, colonne, val * 2);
                    setVal(p, j, colonne, 0);
                    k++;
		}
			
                val = 0;
		val2 = 0;
            }
	}
        
        if (k > 0) 
        {
            return 1;
	}
    
	else 
        {
            return 0;
	}
}

int fusionBasse(jeu *p, int colonne) 
{
    int i, j;
    int k = 0;
    int val = 0;
    int val2 = 0;
    
    for (i =(*p).n; i >= 0; i--) 
    {
        if (getVal(p, i, colonne) != 0) 
        {
            val = getVal(p, i, colonne);
            
            for (j = i-1; j >= 0; j--) 
            {
                if (getVal(p, j, colonne) != 0) 
                {
                    val2 = getVal(p, j, colonne);
                    break;
		}
            }	
			
            if (val == val2) 
            {
                setVal(p, i, colonne, val*2);
		setVal(p, j, colonne, 0);
		k++;
            }
			
            val = 0;
            val2 = 0;
        }
    }
	
    if (k > 0) 
    {
	return 1;
    }
	
    else 
    {
	return 0;
    }
}

int tassageGauche(jeu *p, int ligne) {

	int i, j;
	int k = 0;
	int indiceCaseVide = -1;

	for (i = 0; i < (*p).n; i++) 
        {
            if (getVal(p, ligne, i) == 0 && indiceCaseVide == -1) 
            {
                indiceCaseVide = i;
            }    													//on cherche une case vide en parcourant la ligne, on stocke l'indice

            if (getVal(p, ligne, i) > 0 && indiceCaseVide != -1) 
            {
                setVal(p, ligne, indiceCaseVide, getVal(p, ligne, i));	//on met la premiere valeur non nulle dans la premiere case vide
		setVal(p, ligne, i, 0);
		indiceCaseVide++;
		k++;
            }
	}
	
        if (k > 0) 
        {
            return 1;
	}
        
	else 
        {
            return 0;
	}
}

int tassageDroit(jeu *p, int ligne) 
{
    int i, j;
    int k = 0;
    int indiceCaseVide = -1;

    for (i = (*p).n; i >= 0; i--) 
    {
        if (getVal(p, ligne, i) == 0 && indiceCaseVide == -1) 
        {
            indiceCaseVide = i;
	}
		
        if (getVal(p, ligne, i) > 0 && indiceCaseVide != -1) 
        {
            setVal(p, ligne, indiceCaseVide, getVal(p, ligne, i));
            setVal(p, ligne, i, 0);
            indiceCaseVide--;
            k++;
	}
    }

    if (k > 0) 
    {
        return 1;
    }
	
    else 
    {
        return 0;
    }
}

int tassageHaut(jeu *p, int colonne) 
{
    int i, j;
    int k = 0;
    int indiceCaseVide = -1;

    for (i = 0; i < (*p).n; i++) 
    {
        if (getVal(p, i, colonne) == 0 && indiceCaseVide == -1) 
        {
            indiceCaseVide = i;
	}

	if (getVal(p, i, colonne) > 0 && indiceCaseVide != -1) 
        {
		setVal(p, indiceCaseVide, colonne, getVal(p, i, colonne));
		setVal(p, i, colonne, 0);
		indiceCaseVide++;
		k++;
	}
    }

    if (k > 0) 
    {
        return 1;
    }
	
    else 
    {
        return 0;
    }
}

int tassageBas(jeu *p, int colonne) 
{
    int i, indiceCaseVide;
    int j = 0;
    indiceCaseVide = -1;

    for (i = (*p).n; i >= 0; i--) 
    {
        if (getVal(p, i, colonne) == 0 && indiceCaseVide == -1) 
        {
            indiceCaseVide = i;
	}
        
        if (getVal(p, i, colonne) > 0 && indiceCaseVide != -1) 
        {
            setVal(p, indiceCaseVide, colonne, getVal(p, i, colonne));
            setVal(p, i, colonne, 0);
            indiceCaseVide--;
            j++;
	}
    }
    
    if (j > 0) 
    {
        return 1;
    }
    
    else 
    {
	return 0;
    }
}

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
    int i = 0;
    
    if (direction == 1) 
    {
        i = i + fusionGauche(p, ligne) + tassageGauche(p, ligne);
    }
	
    else 
    {
	i = i + fusionDroite(p, ligne) + tassageDroit(p, ligne);
    }

    if (i > 0) 
    {
	return 1;
    }
	
    else 
    {
	return 0;
    }
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
    int i;
    int j = 0;
    
    for (i = 0; i < (*p).n; i++) 
    {
        j = j + mouvementLigne(p, i, direction);
    }
    
    if (j > 0) 
    {
        return 1;
    }
    
    else 
    {
        return 0;
    }
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
    int i;
    
    if (direction == 1) 
    {
        i = fusionHaute(p, colonne) + tassageHaut(p, colonne);
    }
	
    else 
    {
        i = fusionBasse(p, colonne) + tassageBas(p, colonne);
    }

    if (i > 0) 
    {
	return 1;
    }
	
    else 
    {
	return 0;
    }
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
int mouvementColonnes(jeu * p, int direction)
{
    int i;
    int j = 0;
    
    for (i = 0; i < (*p).n; i++) 
    {
        j = j + mouvementColonne(p, i, direction);
    }
    
    if (j > 0) 
    {
	return 1;
    }
    
    else 
    {
	return 0;
    }
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
int mouvement(jeu * p, int direction)
{
    switch(direction)
    {
        case 0 :
            return mouvementColonnes(p, -1);
            break;
        case 1 :
            return mouvementLignes(p, -1);
            break;
        case 2 :
            return mouvementColonnes(p, 1);
            break;
        case 3 :
            return mouvementLignes(p, 1);
            break;
        default :
            return 0;
            break;
    }
}
