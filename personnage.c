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
	p.posScreen.y=260;
        // scrolling 
	p.poseecran_1.x=200;
        p.poseecran_1.y=200;
        //
	p.posSprite.x=0;
	p.posSprite.y =0;
	p.posSprite.w =p.sprite->w/4;
	p.posSprite.h =p.sprite->h/2;
        p.acceleration=0;
	p.velocity=0.01;
	p.sauter=0 ;
	p.descendre=0;
        
      



return p;
}

////////////////////////////////////////////*************************************************************************
personnage movePerso(personnage p ,Uint32 dt)
{
if (p.direction ==0  )
p.posScreen.x=p.posScreen.x+p.velocity*dt+ 0.5*p.acceleration* dt*dt ; 
printf("%f pas \n ", p.velocity*dt+ 0.5*p.acceleration*dt*dt );

if (p.direction ==1 )
{
p.posScreen.x=p.posScreen.x- p.velocity*dt- 0.5*p.acceleration* dt*dt  ;
printf("%f pas dir 1 \n ", p.velocity*dt+ 0.5*p.acceleration*dt*dt );
}
return p;
}





////////////////////////////////////////////*************************************************************************

personnage sauterPersomonter(personnage p, int hauteur_max, int hauteur_min)
{  

	if (p.sauter==1 && p.descendre==0)
 	{
   		if (p.direction==0)
   		{
                 if (p.poseecran_1.y > hauteur_max)
     		 p.poseecran_1.y=p.poseecran_1.y-1;
                
      		 p.posScreen.x=p.posScreen.x+1;
		
    		}
    
   		else if (p.direction==1 )
   		{
              	if (p.poseecran_1.y > hauteur_max)
    		p.poseecran_1.y=p.poseecran_1.y-1;

    		p.posScreen.x=p.posScreen.x-1;
    
   		}
	

    		if ( p.poseecran_1.y == hauteur_max)
    		{
        	p.descendre = 1;
    		}
	}

 return p;
}

////////////////////////////////////////////*************************************************************************
personnage sauterPersodescendre(personnage p, int hauteur_max, int hauteur_min)
{
	if (p.direction==0)
  	{if (p.poseecran_1.y<hauteur_min)
       	p.poseecran_1.y+=1;
	//if (p.posScreen.x<200 )
       	p.posScreen.x+=1;
   
  	}
	else if (p.direction==1)
  	{ if (p.poseecran_1.y<hauteur_min)
       	p.poseecran_1.y+=1;
       	p.posScreen.x-=1;
  	}

    	if (p.poseecran_1.y == hauteur_min )
    	{   
        p.sauter=0;
        p.descendre = 0;
    	}

return p;
}


////////////////////////////////////////////*************************************************************************

personnage scrollingPersomonter(personnage p, int hauteur_max, int hauteur_min)
{


if (p.sauter==1 && p.descendre==0)
 	{
   		if (p.direction==0)

   		{ 
		  if (p.poseecran_1.x >=7000)// condition rebouclage scrolling
                      p.poseecran_1.x=201;
                 if (p.poseecran_1.y > hauteur_max)
     		 p.poseecran_1.y=p.poseecran_1.y-1;
      		 p.poseecran_1.x=p.poseecran_1.x+1;


    		}
    
   		else if (p.direction==1 )
   		{  
                if (p.poseecran_1.y > hauteur_max)     
    		p.poseecran_1.y=p.poseecran_1.y-1;
		
    		p.poseecran_1.x=p.poseecran_1.x-1;
    
   		}
	

    		if ( p.poseecran_1.y == hauteur_max)
    		{
        	p.descendre = 1;
    		}
	}


return p; 
}















////////////////////////////////////////////*************************************************************************
personnage scrollingPersodescendre(personnage p, int hauteur_max, int hauteur_min)
{      
       


	if (p.direction==0)
  	{
	if (p.poseecran_1.x >=7000)// condition rebouclage scrolling
        p.poseecran_1.x=201;
        if (p.poseecran_1.y<hauteur_min)
       	p.poseecran_1.y+=1;
       	p.poseecran_1.x+=1;
   
  	}
	else if (p.direction==1 )
  	{ 
		if (p.poseecran_1.y<hauteur_min)
       		p.poseecran_1.y+=1;
		
       		p.poseecran_1.x-=1;
		
	  
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




