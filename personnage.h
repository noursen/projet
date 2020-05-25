#include "SDL/SDL.h"
#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#ifdef WIN32
#pragma comment(lib,"sdl.lib")
#pragma comment(lib,"sdlmain.lib")
#endif

#define STAT_SOL 0
#define STAT_AIR 1



typedef struct
{

SDL_Surface* sprite;
SDL_Rect posScreen;
SDL_Rect poseecran_1; // scrolling 
int direction;
SDL_Rect posSprite;
int cmpt;
SDL_Rect posPersoRel;
float acceleration;
float velocity;
int descendre;
int sauter;

}personnage ;

typedef struct
{
	int status;
	float x,y;
	float vx,vy;
}Sprite;




personnage scrollingPersomonter(personnage p, int hauteur_max, int hauteur_min);
personnage sauterPersomonter(personnage p, int hauteur_max, int hauteur_min);
personnage scrollingPersodescendre(personnage p, int hauteur_max, int hauteur_min);
personnage sauterPersodescendre(personnage p, int hauteur_max, int hauteur_min);
personnage initialisePerso( personnage p );
personnage evolutionPerso( personnage p, int hauteur_max, int hauteur_min);

personnage animatePerso(personnage p, int direction);
personnage movePerso(personnage p , Uint32 dt);


#endif
