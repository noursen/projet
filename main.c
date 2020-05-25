#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"







int main(int argc, char *argv[])
{

/********************************** chargement de l'ecran et du background*****************************************/
    SDL_Surface *ecran = NULL;
    SDL_Surface *back;










    SDL_Rect posecran;
    posecran.x=0;
    posecran.y=0;
   
    SDL_Event event;
    int continuer = 1;
    int direction=0;
    Uint32 t_prev, dt=1; 
    int hauteur_max=120;
    int hauteur_min=200;
    SDL_Init(SDL_INIT_VIDEO);
const unsigned int fps = 20;
   
    
    back=IMG_Load("back_annimation.png");
    
    

    ecran = SDL_SetVideoMode(back->w/11,back->h-200,32,  SDL_HWSURFACE);

    SDL_WM_SetCaption("Hammadi el Botti", NULL);


   /***************************************************************************/




    /* ********************************Chargement du personnage*************************************************  */
    personnage perso;
    perso=initialisePerso(perso);
    perso.poseecran_1.h=back->h;
    perso.poseecran_1.w=back->w/11;
   


    /**************************************************************************************************************/

//
















while (continuer)
    {   t_prev=SDL_GetTicks();
 if(perso.acceleration<=0)
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
                        // perso.velocity+=0.0001;
			perso.acceleration+=0.05;
                        break;
                    case SDLK_LEFT: // Flèche gauche

                        direction=1;
			//perso.velocity=5;
  			perso.acceleration+=0.05 ;


                        break;
                   case SDLK_UP: ////// sauttttttterrrrrrrrrrr


                   perso.sauter=1;

                  


                     break;
                }
                break;
        }



///////////////// avanver 
if (direction ==1 ||direction==0 )
{ 
    if (perso.posScreen.x<200 || (perso.poseecran_1.x <=200 && perso.direction==1 ))// move no scrolling 
          {perso=movePerso(perso, dt);
	   perso.poseecran_1.x=200;
	   }

    else {                               // move with scrolling 

	  	if (perso.direction==0)
           	{ 
			if (perso.poseecran_1.x >=7000)// condition rebouclage scrolling 
                 	perso.poseecran_1.x=201;
	    	//perso.poseecran_1.x+=3;
		perso.poseecran_1.x=perso.poseecran_1.x+perso.velocity*dt+ 0.5*perso.acceleration* dt*dt   ; 
printf("\n ******%f pas ***********\n ", +perso.velocity*dt+ 0.5*perso.acceleration* dt*dt);
	   	}
          	else 
            	//perso.poseecran_1.x-=3;
		{perso.poseecran_1.x=perso.poseecran_1.x- perso.velocity*dt- 0.5*perso.acceleration* dt*dt ;
		printf("\n ******%f pas dir 1 ***********\n ", +perso.velocity*dt+ 0.5*perso.acceleration* dt*dt);
		}
         perso.posScreen.x=200;
         }


    perso=animatePerso(perso, direction);
}
///////////// sauter BEFORE SCROLLING 

if (perso.sauter==1 && perso.descendre==0 &&  perso.posScreen.x <200 && perso.poseecran_1.x<=200 )   // monter 
	
        { perso=   sauterPersomonter(perso,  hauteur_max, hauteur_min);
          perso.poseecran_1.x=200;

         }
if (perso.sauter==1 && perso.descendre==1 &&  perso.posScreen.x <200 && perso.poseecran_1.x<=200 )// descendre
    { 
	perso=   sauterPersodescendre(perso,  hauteur_max, hauteur_min);
	perso.poseecran_1.x=200;
    }
//// sauter between the too zones 

if (perso.poseecran_1.x ==200 && perso.posScreen.x ==200 && perso.sauter==1 && perso.descendre==0 && perso.direction==0)//monter vers la droite
{
perso.poseecran_1.x=201;
}
if (perso.poseecran_1.x ==200 && perso.posScreen.x ==200 && perso.sauter==1 && perso.descendre==0 && perso.direction==1)//monter vers la gauche
{
perso.posScreen.x=199;
}
if(perso.poseecran_1.x ==200&&perso.posScreen.x ==200&& perso.sauter==1 && perso.descendre== 1 && perso.direction==1)//descendre vers la gauche
{

perso.posScreen.x=199;

}
if (perso.poseecran_1.x ==200 && perso.posScreen.x ==200 && perso.sauter==1 && perso.descendre== 1 && perso.direction==0)// descendre v droite

{
perso.poseecran_1.x=201;
}

//////////////// SAUTER AFTER SCROLLING 

if (perso.sauter==1 && perso.descendre==0 &&  perso.posScreen.x ==200 && perso.poseecran_1.x>200)  // monter 
     {	perso=   scrollingPersomonter(perso,  hauteur_max, hauteur_min);
	perso.posScreen.x=200;
       
     }   

if (perso.sauter==1 && perso.descendre==1 &&  perso.posScreen.x ==200 && perso.poseecran_1.x>200 )// descendre 
     {
	perso=   scrollingPersodescendre(perso,  hauteur_max, hauteur_min);
        perso.posScreen.x=200;
     } 
dt =SDL_GetTicks()-t_prev; 
if (perso.acceleration>0 )
 perso.acceleration-=0.017;
  

if (1000/fps >dt)
 SDL_Delay(1000/fps-dt);
/*printf("\n l acceleration est %f , la vitesse est %f ",perso.acceleration,perso.velocity);*/}



    SDL_FreeSurface(ecran);
    SDL_Quit();

    return EXIT_SUCCESS;
}



