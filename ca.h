#ifndef CA__H_
#define CA__H_

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "cacon.h"
using namespace std;
class cacon;
class ca{
    public:
        int size_ca =1, spriteclips = 10;
        void load_anh(string pathright, string pathleft, SDL_Renderer *gRenderer);
        void handle_event(SDL_Event &e, SDL_Rect SpriteClips[]);
        void move(SDL_Event &e, SDL_Rect SpriteClips[]);
        void render_ca(SDL_Renderer *gRenderer);
        bool check_collision(cacon camini);
        bool check_nearby(cacon camini);
        int toadox=1000/2 -50;
        int toadoy=0;
        int velx =0, vely=0;
        SDL_Rect *current_clip;
        int frame =0;
        SDL_Texture *concadan;
        SDL_Texture *concadan_right;
        SDL_Texture *concadan_left;
        ~ca(){
        SDL_DestroyTexture(concadan);
        SDL_DestroyTexture(concadan_left);
        SDL_DestroyTexture(concadan_right);}
};


#endif // CA__H_
