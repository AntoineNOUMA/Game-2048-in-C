/*******************************************************
Nom           : couleurs_terminal.h
Auteur        : Mathieu Lacroix
Version       : V1
Date          : 16/11/16
Informations  : Contient la définition des fonctions
                - color_printf
                - clear_terminal
********************************************************/

#include "myHeader.h"


void effaceTerminal()
{
  printf("\033[2J");
  printf("\033[0;0H");
}

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

