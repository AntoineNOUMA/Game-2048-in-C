#include "myHeader.h"
#define MAX 2048

static struct termios   save_termios;
static int term_saved;
static int fd = 0;

static int tty_raw() {
  struct termios  buf;

  if (tcgetattr(fd, &save_termios) < 0)
    return -1;

  buf = save_termios;
  buf.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  buf.c_iflag &= ~(BRKINT | ICRNL | ISTRIP | IXON);
  buf.c_cflag &= ~(CSIZE | PARENB);
  buf.c_cflag |= CS8;
  buf.c_cc[VMIN] = 1;
  buf.c_cc[VTIME] = 0;

  if (tcsetattr(fd, TCSAFLUSH, &buf) < 0)
    return -1;

  term_saved = 1;
  return 0;
}

static void tty_reset() {
  if (term_saved)
    if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
      exit(-1);
}


/*
 * Fin du mode saisie "sans retour chariot" : on revient à la normale
 */
void finTerminalSansR()
{
  
   if (term_saved)
    if (tcsetattr(fd, TCSAFLUSH, &save_termios) < 0)
      exit(-1);
}

/*
 * Début du mode saisie "sans retour chariot" : 
 * Il n'est pas nécessaire d'appuyer sur la touche entrée pour saisir une valeur.
 * La valeur saisie ne s'affiche pas.
 */
int debutTerminalSansR()
{
  if (tty_raw() != 0)
    return 0;
  atexit(tty_reset);
  return 1;
}

/*
 * Lecture d'une touche. La fonction renvoie :
 *   - KEY_UP, KEY_DOWN, KEY_LEFT ou KEY_RIGHT si l'utilisateur appuie sur une des flèches
 *   - KEY_ESCAPE si l'utilisateur appuie sur la touche Echap
 *   - NO_KEY si l'utilisateur appuie sur une autre touche
 */
toucheFleche lectureFleche()
{
  char buf[MAX];
  int n = read(0, (void*) buf, MAX);
  switch (n)
  {
    case 1:
      return buf[0] == '' ? KEY_ESCAPE : NO_KEY;
    case 3:
      if (buf[0] == '' && buf[1] == '[')
      {
        switch (buf[2])
        {
          case 'A': return KEY_UP;
          case 'B': return KEY_DOWN;
          case 'C': return KEY_RIGHT;
          case 'D': return KEY_LEFT;
        }
      }
  }
  return NO_KEY;
}

/*
 * Fonction effaçant le terminal
 */
void clear_terminal()
{
  printf("\033[2J");
  printf("\033[0;0H");
}

/*
 * Printf en couleur. Les deux premiers paramètres sont les couleurs d'écriture et de fond (mettre une des valeurs parmi : 
 * BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN et WHITE).
 * Les parmètres suivants sont comme le printf "normal" : chaîne de format puis toutes les valeurs à afficher
 */
int color_printf(couleur fg, couleur bg, const char * format, ...)
{
  int res;
  va_list args;
  printf("\x1B[1;%02d;%02dm", fg + 30, bg + 40);
  va_start(args, format);
  res = vprintf(format, args);
  va_end(args);
  printf("\x1B[00m");
  return res;
}

/*Définition de la fonction couleurNombre
 * 
 * Permet d'attribuer une couleur à un nombre en fonction de sa valeur
 * Les nombre de même valeur auront la même couleur
 * 
 * \param x : entier représentant un nombre dans la grille de jeu
 */
couleur couleurNombre(int x) 
{				
    couleur tabCouleur[6] = {RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN};
    int i = 2;
    int j = 0;
    if (x == 0) 
    {
        return BLACK;
    }
    
    else 
    {
        while (i < x) 
        {
            j++;
            
            if (j == 6) 
            {
                j = 0;
            }
            
            i = i * 2;
	}
    }
	
    return tabCouleur[j];
} 

/*Définition de la fonction tailleNombre
 * 
 * Permet d'attribuer une taille à un nombre en fonction de sa valeur
 * \param x : entier représentant un nombre dans la grille de jeu
 */
int tailleNombre(int x)
{
    if (x < 10)
    {
        return 1;
    }
	
    if (x < 100)
    {
        return 2;
    }
	
    if (x < 1000)
    {
        return 3;
    }
	
    if (x < 10000)
    {
        return 4;
    }
	
    if (x < 100000)
    {
        return 5;
    }
	
    if (x < 1000000)
    {
        return 6;
    }
    
    if (x < 100000000)
    {
        return 7;
    }

	return 8;
} 							//retourne la taille du x donné

/*Définition de la fonction affichageNombre
 * 
 * Permet de centrer le nombre dans la ligne de l'écrire en blanc avec le fond correspondant à sa valeur
 * \param x : entier représentant un nombre dans la grille de jeu
 */
void affichageLigne(int x) 
{
    couleur tabCouleur = couleurNombre(x);
    couleur white = WHITE;
    int tailleX = tailleNombre(x);
    
    if (x == 0) {
		color_printf(white,tabCouleur,"   .   ");
	}
	else if (tailleX == 1) {
		color_printf(white,tabCouleur,"   %d   ",x);
	}
	else if (tailleX == 2) {
		color_printf(white,tabCouleur,"  %d   ",x);
	}
	else if (tailleX == 3) {
		color_printf(white,tabCouleur,"  %d  ",x);
	}
	else if (tailleX == 4) {
		color_printf(white,tabCouleur," %d  ",x);	
	}
	else if (tailleX == 5) {
		color_printf(white,tabCouleur," %d ",x);
	}
	else if (tailleX == 6) {
		color_printf(white,tabCouleur,"%d ",x);
	}
	else if (tailleX == 7) {
		color_printf(white,tabCouleur,"%d",x);
	}
	else {
		printf("Erreur");
	}
}

void affichage(jeu * p) 
{
    clear_terminal();
    int cote = (*p).n;
    int coteMOD = cote;
    int i;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    couleur tabCouleur;
    
    for (i=0; i<cote; i++) 
    {
        for (i2; i2<coteMOD; i2++) 
        {
            tabCouleur = couleurNombre(((*p).grille)[i2]);
            color_printf(WHITE,tabCouleur,"       ");
	}
		
        printf("\n");

	for (i3; i3<coteMOD; i3++) 
        {
            affichageLigne(((*p).grille)[i3]);
	}
		
        printf("\n");

	for (i4; i4<coteMOD; i4++) 
        {
            tabCouleur = couleurNombre(((*p).grille)[i4]);
            color_printf(WHITE,tabCouleur,"       ");
	}
		
        printf("\n");
        coteMOD = coteMOD + cote;
    }
}