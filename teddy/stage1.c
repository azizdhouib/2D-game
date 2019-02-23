#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "stage1.h"
/*int scrolling(SDL_Surface* fond , int x)
{
x--;
//if(x>=2048-fond->w)
//x=0;
return x;
}*/
/*void apply_surface(int x,int y ,SDL_Surface* source,SDL_Surface* destination )
{
SDL_Rect offset;
offset.x=x;
offset.y=y;
SDL_BlitSurface(source,NULL,destination,&offset);


}
*/
SDL_Color GetPixel (SDL_Surface* pSurface, int x, int y)
{

  SDL_Color color;
  Uint32 col = 0;
  char *pPosition = (char*) pSurface -> pixels;
  pPosition += (pSurface -> pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col, pPosition, pSurface->format->BytesPerPixel);
  SDL_GetRGB (col, pSurface->format, &color.r, &color.g, &color.b);
  return (color);
}

int detecter_collision_background (SDL_Surface *image, SDL_Rect position,int z)
{
  SDL_Color color;
  color = GetPixel (image, position.x+(z*1200)+50, position.y-180);
  if (color.r==255 && color.g==255 && color.b==255) {printf("sfdf");
return 1;}
  return 0;
}
int detecter_collision_backgrounddown (SDL_Surface *image, SDL_Rect position,int z)
{
  SDL_Color color;
  color = GetPixel (image, position.x+(z*1200)+20, position.y-150);
  if (color.r==255 && color.g==255 && color.b==255) {printf("sfdf");
return 1;}
  return 0;
}
int detecter_collision_backgroundleft (SDL_Surface *image, SDL_Rect position,int z)
{
  SDL_Color color;
  color = GetPixel (image, position.x+(z*1200), position.y-180);
  if (color.r==255 && color.g==255 && color.b==255) {printf("sfdf");
return 1;}
  return 0;
}
void intro(SDL_Surface *fenetre)
{SDL_Event event;
  SDL_Rect posintro;
  posintro.x=0;
  posintro.y=0;
  SDL_Surface *introduction=IMG_Load("intro1.jpg");
  SDL_BlitSurface(introduction,NULL,fenetre,&posintro);
  SDL_Flip(fenetre);
  SDL_Delay(4000);
introduction=IMG_Load("intro2.jpg");
SDL_BlitSurface(introduction,NULL,fenetre,&posintro);
  SDL_Flip(fenetre);
  SDL_Delay(4000);
introduction=IMG_Load("intro3.jpg");
SDL_BlitSurface(introduction,NULL,fenetre,&posintro);
  SDL_Flip(fenetre);
  SDL_Delay(3000);
  SDL_FreeSurface(introduction);
}

int stage1()

{   Mix_Volume(0,MIX_MAX_VOLUME/10);
 
    SDL_Event event;
    SDL_Surface *ecran = NULL,*stage1 = NULL,*girl = NULL,*vie1= NULL,*vie2= NULL,*vie3= NULL ,*stage = NULL,*enemi=NULL;
    int continuer = 1,i=100,a=0 ,direction=0;
    SDL_EnableKeyRepeat(4,4);
    SDL_Rect positionFond,positiongirl,positionvie1,positionvie2,positionvie3,positionenemi;
    positionFond.x = 0;
    positionFond.y = 230;
    positiongirl.x =0;
    positiongirl.y =380;
    positionvie1.x = 10;
    positionvie1.y = 20;
    positionvie2.x = 10;
    positionvie2.y = 20;
    positionvie3.x = 10;
    positionvie3.y = 20;
positionenemi.x=5990;
positionenemi.y=380;
    SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
 intro(ecran);
    ecran = SDL_SetVideoMode(1200,700,32,SDL_HWSURFACE);
    vie1=IMG_Load("vie1.png");
    vie2=IMG_Load("vie2.png");
    vie3=IMG_Load("vie3.png");
    girl=IMG_Load("char11.png");    
    stage1=IMG_Load("stage1.png");
    stage=IMG_Load("mask.png");
    enemi=IMG_Load("char5.png");
    SDL_BlitSurface(vie3, NULL, ecran, &positionvie3);
    SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
    SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
SDL_BlitSurface(enemi, NULL, ecran, &positionenemi);
   
    SDL_Flip(ecran);
    int z=0,score=0;
    int xf=positionFond.x;
    while (continuer)

	{
         while(detecter_collision_backgrounddown (stage,positiongirl,z)==0)
          {positiongirl.y+=2;
        if(direction==0){positiongirl.x+=2;
if      (i%4==0){ girl=IMG_Load("char11.png");i++;}
			else if (i%4==1){ girl=IMG_Load("char22.png");i++;}
			else if (i%4==2){ girl=IMG_Load("char33.png");i++;}
			else if (i%4==3){ girl=IMG_Load("char11.png");i++;}}
else
{if      (i%4==0){ girl=IMG_Load("char55.png");i++;}
			else if (i%4==1){ girl=IMG_Load("char66.png");i++;}
			else if (i%4==2){ girl=IMG_Load("char77.png");i++;}
			else if (i%4==3){ girl=IMG_Load("char55.png");i++;}
positiongirl.x-=2;}
positionFond.x=positionFond.x-(z*1200);
SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);

			SDL_Flip(ecran);	  
		}
 	  SDL_PollEvent(&event);
	  switch(event.type)

        {
	  case SDL_QUIT: continuer = 0;break;
	    case SDL_KEYDOWN :
 
		{

		if (event.key.keysym.sym == SDLK_RIGHT)
		{
                direction=0;

		if      (i%4==0){ girl=IMG_Load("char11.png");SDL_Delay(30);i++;}
		else if (i%4==1){ girl=IMG_Load("char22.png");SDL_Delay(30);i++;}
		else if (i%4==2){ girl=IMG_Load("char33.png");SDL_Delay(30);i++;}
		else if (i%4==3){ girl=IMG_Load("char11.png");SDL_Delay(30);i++;}
		if (positiongirl.x<1150 && detecter_collision_background (stage,positiongirl,z)==0 )
			{positiongirl.x=positiongirl.x+15;}
		if (positiongirl.x>1100 && z<4 )
	    {
		z++;
		positiongirl.x=10;
                if(score==0)
                {SDL_BlitSurface(vie2, NULL, ecran, &positionvie3);
		score++;
		}
		else
		{
		SDL_BlitSurface(vie1, NULL, ecran, &positionvie3);
		score++;		
		}
              
		SDL_Flip(ecran);
		}
		SDL_Flip(ecran);
 		positionFond.x=positionFond.x-(z*1200);		
 		SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
		SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
		SDL_Flip(ecran);
                }  
     
		else if (event.key.keysym.sym == SDLK_LEFT)
		{
                         direction=1;
			if      (i%4==0){ girl=IMG_Load("char55.png");SDL_Delay(30);i++;}
			else if (i%4==1){ girl=IMG_Load("char66.png");SDL_Delay(30);i++;}
			else if (i%4==2){ girl=IMG_Load("char77.png");SDL_Delay(30);i++;}
			else if (i%4==3){ girl=IMG_Load("char55.png");SDL_Delay(30);i++;}
if(positiongirl.x>10 && detecter_collision_backgroundleft (stage,positiongirl,z)==0)			
{
positiongirl.x=positiongirl.x-15;
}
			if ( positiongirl.x<10 && z>0 )
		   {
				
				if(z>0)
				z--;
				
				positiongirl.x=1140;

				SDL_Flip(ecran);
			}
            
            positionFond.x=positionFond.x-(z*1200);


            SDL_Flip(ecran);
			SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
			SDL_Flip(ecran);
		}
             if (event.key.keysym.sym == SDLK_UP && direction==1)
        	  {
                   if      (i%4==0){ girl=IMG_Load("char55.png");i++;}
			else if (i%4==1){ girl=IMG_Load("char66.png");i++;}
			else if (i%4==2){ girl=IMG_Load("char77.png");i++;}
			else if (i%4==3){ girl=IMG_Load("char55.png");i++;}
                     
			positiongirl.x=positiongirl.x-40;
                     positiongirl.y=positiongirl.y-50;
                     SDL_Delay(65);
			SDL_Flip(ecran);
			positionFond.x=positionFond.x-(z*1200);
			SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
			SDL_Flip(ecran);
		     positiongirl.x=positiongirl.x-40;
                     positiongirl.y=positiongirl.y-50;
		     SDL_Delay(65);
			SDL_Flip(ecran);
			positionFond.x=positionFond.x-(z*1200);
			SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
			SDL_Flip(ecran);
		    
                      


	          }
              if (event.key.keysym.sym == SDLK_UP && direction==0)
        	  { 
                   if      (i%4==0){ girl=IMG_Load("char11.png");i++;}
			else if (i%4==1){ girl=IMG_Load("char22.png");i++;}
			else if (i%4==2){ girl=IMG_Load("char33.png");i++;}
			else if (i%4==3){ girl=IMG_Load("char11.png");i++;}
                    
					positiongirl.x=positiongirl.x+40;
                     positiongirl.y=positiongirl.y-50;
                     SDL_Delay(65);
				SDL_Flip(ecran);
				positionFond.x=positionFond.x-(z*1200);
			SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
			SDL_Flip(ecran);
		     positiongirl.x=positiongirl.x+40;
                     positiongirl.y=positiongirl.y-50;
		     SDL_Delay(65);
				SDL_Flip(ecran);
			positionFond.x=positionFond.x-(z*1200);
			SDL_BlitSurface(stage1, NULL, ecran, &positionFond);
			SDL_BlitSurface(girl, NULL, ecran, &positiongirl);
			SDL_Flip(ecran);
		     

	          }
		


		}


	 

        }
   }
  // apply_surface(xm, ym, girl, ecran);

   SDL_FreeSurface(stage1);
SDL_FreeSurface(girl); 
} 
 
