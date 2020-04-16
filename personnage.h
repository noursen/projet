#include "SDL/SDL.h"
#ifndef FONCTIONS_H_
#define FONCTIONS_H_



typedef struct
{

SDL_Surface* sprite;
SDL_Rect posScreen;
SDL_Rect poseecran_1; // scrolling 
int direction;
SDL_Rect posSprite;
int cmpt;
SDL_Rect posPersoRel;
int sauter ;
int descendre;


}personnage ;



personnage initialisePerso( personnage p );
personnage evolutionPerso( personnage p, int hauteur_max, int hauteur_min,int x_saut);
personnage animatePerso(personnage p, int direction);
personnage movePerso(personnage p);
#endif
