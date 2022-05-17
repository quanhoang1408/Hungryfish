#ifndef CACON__H_
#define CACON__H_

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"ca.h"
using namespace std;

class cacon{
    public:
        int SCREEN_WIDTH = 1000;
        int sizeca = 1, spriteclips = 7;
        int toadox , toadoy ;
        int frame =0;
        int speed = 0;
        int f=0;
        SDL_Rect* current_clip;
        SDL_Texture* mTexture;
        SDL_Texture* leftTexture;
        SDL_Texture* rightTexture;
        bool direction = false;
        void load_anh(string pathleft, string pathright, bool direction, SDL_Renderer *gRenderer);
        void move(bool direction,SDL_Rect SpriteClips[]);
        void render(SDL_Renderer *gRenderer);
};
#endif // CACON__H_
