#include "cacon.h"
#include "ca.h"
#include "SDL_utils.h"
class cacon;
bool ca::check_collision(cacon camini){
    if(toadox + current_clip->w  <= camini.toadox){
        return false;
    }
    if(toadox >= camini.toadox+camini.current_clip->w){
        return false;
    }
    if(toadoy + current_clip->h <= camini.toadoy){
        return false;
    }
    if(toadoy >= camini.toadoy + camini.current_clip->h ){
        return false;
    }
    return true;
}
void ca::load_anh(string pathright, string pathleft,SDL_Renderer *gRenderer){
    SDL_Surface *loadsurface1 = IMG_Load(pathright.c_str());
    SDL_SetColorKey(loadsurface1,SDL_TRUE, SDL_MapRGB(loadsurface1->format,0xFF,0xFF,0xFF));
    concadan_right = SDL_CreateTextureFromSurface(gRenderer,loadsurface1);
    SDL_Surface *loadsurface2 = IMG_Load(pathleft.c_str());
    SDL_SetColorKey(loadsurface2,SDL_TRUE, SDL_MapRGB(loadsurface2->format,0xFF,0xFF,0xFF));
    concadan_left = SDL_CreateTextureFromSurface(gRenderer, loadsurface2);
    concadan = concadan_right;
}
void ca::move(SDL_Event &e, SDL_Rect SpriteClips[]){
    if(e.type == SDL_MOUSEMOTION);
    else{
    toadox += velx;
    toadoy += vely;
    }
}
void ca::render_ca(SDL_Renderer *gRenderer){
    SDL_Rect toadoca = {toadox,toadoy,current_clip->w, current_clip->h};
    SDL_RenderCopy(gRenderer, concadan,current_clip, &toadoca);
}
void ca::handle_event(SDL_Event &e, SDL_Rect SpriteClips[]){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if(keystates[SDL_SCANCODE_LEFT]){
            concadan = concadan_left;
            toadox-=2;
    }
    if(keystates[SDL_SCANCODE_RIGHT]){
            concadan = concadan_right;
            toadox+=2;
    }
    if(keystates[SDL_SCANCODE_UP]){
            toadoy-=2;
    }
    if(keystates[SDL_SCANCODE_DOWN]){
            toadoy +=2;
    }
    if(keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_LEFT]){
        current_clip = &SpriteClips[(frame/3)+spriteclips];
        frame++;
        if(frame == 9) frame =0;
    }
    if(keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_UP]){
        current_clip = &SpriteClips[(frame/3)+spriteclips];
        frame++;
        if(frame == 9) frame =0;
    }
}
