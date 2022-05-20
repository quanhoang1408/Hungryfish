#include "cacon.h"
void cacon::load_anh(string pathleft, string pathright, bool direction, SDL_Renderer *gRenderer)
{
    SDL_Surface* loadedSurface1 = IMG_Load(pathleft.c_str());
    SDL_SetColorKey(loadedSurface1,SDL_TRUE, SDL_MapRGB(loadedSurface1->format,0xFF,0xFF,0xFF));
    leftTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface1);
    SDL_Surface* loadedSurface2 = IMG_Load(pathright.c_str());
    SDL_SetColorKey(loadedSurface2, SDL_TRUE, SDL_MapRGB(loadedSurface2->format,0xFF,0xFF,0xFF));
    rightTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface2);
    if(direction){
        mTexture = rightTexture;
    }
    else{
        mTexture = leftTexture;
    }
}
void cacon::move(bool direction, SDL_Rect SpriteClips[])
{
    if(direction){
        toadox++;
        current_clip = &SpriteClips[(f/100)+spriteclips];
        f++;
        if(f==300) f=0;
        if(toadox == SCREEN_WIDTH){
            toadox =0;
        }
    }
    else{
        toadox--;
        current_clip = &SpriteClips[(f/100)+spriteclips];
        f++;
        if(f==300) f=0;
        if(toadox ==0){
            toadox = SCREEN_WIDTH;
        }
    }
}

void cacon::render(SDL_Renderer *gRenderer)
{
    SDL_Rect quadrad = {toadox, toadoy, current_clip->w, current_clip->h};
    SDL_RenderCopy( gRenderer, mTexture, current_clip, &quadrad);
}

