#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "personnage.h"


////////////////////////////////////////////*************************************************************************
personnage initialisePerso( personnage p )
{
        p.sprite=IMG_Load("perso.png");
        p.cmpt=0;

	p.direction=0;

	p.posScreen.x=0;
	p.posScreen.y=230;
        // scrolling 
	p.poseecran_1.x=200;
        p.poseecran_1.y=230;
        //
	p.posSprite.x=0;
	p.posSprite.y =0;
	p.posSprite.w =p.sprite->w/4;
	p.posSprite.h =p.sprite->h/2;
        
	p.sauter=0 ;
	p.descendre=0;



return p;
}

////////////////////////////////////////////*************************************************************************
personnage movePerso(personnage p)
{

if (p.direction ==0)
p.posScreen.x=p.posScreen.x+3;

if (p.direction ==1 || (p.direction ==1 && p.poseecran_1.x<=200))
p.posScreen.x=p.posScreen.x-3;

return p;
}





////////////////////////////////////////////*************************************************************************

personnage sauterPersomonter(personnage p, int hauteur_max, int hauteur_min,int x_saut)
{  

	if (p.sauter==1 && p.descendre==0)
 	{
   		if (p.direction==0)
   		{ 
     		 p.posScreen.y=p.posScreen.y-2;
      		 p.posScreen.x=p.posScreen.x+2;

    		}
    
   		else if (p.direction==1 )
   		{  
    		p.posScreen.y=p.posScreen.y-2;
    		p.posScreen.x=p.posScreen.x-2;
    
   		}
	

    		if ( p.posScreen.y <= hauteur_max)
    		{
        	p.descendre = 1;
    		}
	}

 return p;
}

////////////////////////////////////////////*************************************************************************
personnage sauterPersodescendre(personnage p, int hauteur_max, int hauteur_min,int x_saut)
{
	if (p.direction==0)
  	{
       	p.posScreen.y+=2;
       	p.posScreen.x+=2;
   
  	}
	else if (p.direction==1)
  	{ 
       	p.posScreen.y+=2;
       	p.posScreen.x-=2;
  	}

    	if (p.posScreen.y == hauteur_min )
    	{   
        p.sauter=0;
        p.descendre = 0;
    	}

return p;
}


////////////////////////////////////////////*************************************************************************

personnage scrollingPersomonter(personnage p, int hauteur_max, int hauteur_min,int x_saut, int back_w)
{


if (p.sauter==1 && p.descendre==0)
 	{
   		if (p.direction==0)

   		{ 
		  if (p.poseecran_1.x ==7250)// condition rebouclage scrolling
                      p.poseecran_1.x=201;
     		 p.poseecran_1.y=p.poseecran_1.y-2;
      		 p.poseecran_1.x=p.poseecran_1.x+2;

    		}
    
   		else if (p.direction==1 && p.poseecran_1.x>200)
   		{  
                      
    		p.poseecran_1.y=p.poseecran_1.y-2;
    		p.poseecran_1.x=p.poseecran_1.x-2;
    
   		}
	

    		if ( p.poseecran_1.y <= hauteur_max)
    		{
        	p.descendre = 1;
    		}
	}

return p; 
}















////////////////////////////////////////////*************************************************************************
personnage scrollingPersodescendre(personnage p, int hauteur_max, int hauteur_min,int x_saut, int back_w)
{      
       


	if (p.direction==0)
  	{
	if (p.poseecran_1.x ==7250)// condition rebouclage scrolling
        p.poseecran_1.x=201;

       	p.poseecran_1.y+=2;
       	p.poseecran_1.x+=2;
   
  	}
	else if (p.direction==1 && p.poseecran_1.x>200)
  	{ 
	
       	p.poseecran_1.y+=2;
       	p.poseecran_1.x-=2;
  	}

    	if (p.poseecran_1.y == hauteur_min )
    	{   
        p.sauter=0;
        p.descendre = 0;
    	}

return p;
}
////////////////////////////////////////////*************************************************************************





personnage animatePerso(personnage p, int direction)
{


//p.posSprite.y =p.direction;
if (direction!= p.direction )
{p.cmpt=0;
p.direction=direction;

}
if (p.direction ==1)
{
p.posSprite.y=p.sprite->h/2;

}
else
{
p.posSprite.y=0;

}
if (p.cmpt== 3)
{

p.posSprite.x =0;
p.cmpt=0;
}
else
{
p.posSprite.x = p.posSprite.x + p.posSprite.w;
p.cmpt=p.cmpt+1;

}


return p;
}



