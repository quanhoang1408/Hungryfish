#ifndef SDL_UTILS__H_
#define SDL_UTILS__H_
#include <iostream>
#include<SDL.h>
#include <SDL_image.h>
using namespace std;
void init(SDL_Window*&window, SDL_Renderer * &renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);

SDL_Texture *loadBackground(SDL_Renderer * gRenderer,string path);
void renderBackground(SDL_Texture *background,SDL_Renderer *gRenderer);
int shark_incoming(SDL_Texture* shark, SDL_Renderer* renderer, bool direction, SDL_Rect current, int frame);
#endif // SDL_UTILS__H_

