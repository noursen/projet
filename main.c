#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"
/*testtttt*/





int main(int argc, char *argv[])
{

/********************************** chargement de l'ecran et du background*****************************************/
    SDL_Surface *ecran = NULL;
    SDL_Surface *back;

char text[100];

    SDL_Rect posecran;
    SDL_Rect marge_scroll;
    SDL_Event event;
    int continuer = 1;
    int direction=0;
    
    int hauteur_max=160;
    int hauteur_min=230;
    SDL_Init(SDL_INIT_VIDEO);
    int x_saut;
   
    posecran.x=0;
    posecran.y=0;
    back=IMG_Load("back_annimation.png");
    posecran.w=back->w/11;
    posecran.h=back->h-200;
    marge_scroll.x=0;
    marge_scroll.y=200;
    marge_scroll.h=back->h-200;
    marge_scroll.w=back->w/11;
    

    ecran = SDL_SetVideoMode(back->w/11,back->h-200,32,  SDL_HWSURFACE);

    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);

    SDL_BlitSurface(back,&marge_scroll,ecran,&posecran);
   /***************************************************************************/




    /* ********************************Chargement du personnage*************************************************  */
    personnage perso;
    perso=initialisePerso(perso);
    perso.poseecran_1.h=back->h;
    perso.poseecran_1.w=back->w/11;
   


    /**************************************************************************************************************/

//





while (continuer)
    {
        direction=3;
        SDL_BlitSurface(back,&perso.poseecran_1,ecran,&posecran);
	SDL_BlitSurface(perso.sprite,&perso.posSprite,ecran,&perso.posScreen);
        SDL_Flip(ecran);

 SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {

                    case SDLK_RIGHT:
                        direction=0;

                        break;
                    case SDLK_LEFT: // Flèche gauche

                        direction=1;

                        break;
                   case SDLK_UP: ////// sauttttttterrrrrrrrrrr


                   perso.sauter=1;
                   x_saut=perso.posScreen.x;




                     break;
                }
                break;
        }



///////////////// avanver 
if (direction ==1 ||direction==0 )
{
    if (perso.posScreen.x<200 || (perso.poseecran_1.x <=200 && perso.direction==1 ))// move no scrolling 
          perso=movePerso(perso);


    else {                               // move with scrolling 

	  if (perso.direction==0)
           { 
		if (perso.poseecran_1.x >=7000)// condition rebouclage scrolling 
                 perso.poseecran_1.x=201;
	    perso.poseecran_1.x+=3;
	   }
          else 
            perso.poseecran_1.x-=3;
         }


    perso=animatePerso(perso, direction);
}

///////////// sauter BEFORE SCROLLING 

if (perso.sauter==1 && perso.descendre==0 &&  x_saut <=200 )   // monter 
	perso=   sauterPersomonter(perso,  hauteur_max, hauteur_min, x_saut);
        

if (perso.sauter==1 && perso.descendre==1 &&  x_saut <=200)// descendre

	perso=   sauterPersodescendre(perso,  hauteur_max, hauteur_min, x_saut);


//////////////// SAUTER AFTER SCROLLING 

if (perso.sauter==1 && perso.descendre==0 &&  x_saut >200)   // monter 
	perso=   scrollingPersomonter(perso,  hauteur_max, hauteur_min, x_saut, back->w);
        

if (perso.sauter==1 && perso.descendre==1 &&  x_saut >200)// descendre 

	perso=   scrollingPersodescendre(perso,  hauteur_max, hauteur_min, x_saut, back->w);

 }



    SDL_FreeSurface(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}


