#include "SDL_utils.h"

void init(SDL_Window*&gWindow, SDL_Renderer * &gRenderer, int SCREEN_WIDTH, int SCREEN_HEIGHT){
    gWindow = SDL_CreateWindow("Big_game_test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
}
 SDL_Texture *loadBackground(SDL_Renderer *gRenderer){
    SDL_Surface *loadsurface = IMG_Load("background.png");
    SDL_Texture *background = SDL_CreateTextureFromSurface(gRenderer,loadsurface);
    SDL_FreeSurface(loadsurface);
    return background;
}
void renderBackground(SDL_Texture *background, SDL_Renderer *gRenderer){
    SDL_RenderCopy(gRenderer, background, nullptr, nullptr);
}
