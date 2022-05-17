#include <iostream>
#include <SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>
#include <stdlib.h>
#include <time.h>

#include "ca.h"
#include "cacon.h"
#include "SDL_utils.h"
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
int main(int argc, char* argv[])
{
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    TTF_Init();
    bool quit = false;
    SDL_Event e;
    int score = 0;
    SDL_Rect SpriteClips[23];
    SpriteClips[0].x = 0;
    SpriteClips[0].y=0;
    SpriteClips[0].w = 264;
    SpriteClips[0].h = 161;
    SpriteClips[1].x = 264;
    SpriteClips[1].y=0;
    SpriteClips[1].w = 256;
    SpriteClips[1].h = 161;
    SpriteClips[2].x = 520;
    SpriteClips[2].y = 0;
    SpriteClips[2].w = 280;
    SpriteClips[2].h = 161;

    SpriteClips[3].x = 0;
    SpriteClips[3].y = 0;
    SpriteClips[3].w = 150;
    SpriteClips[3].h = 205;

    SpriteClips[4].x = 152;
    SpriteClips[4].y = 0;
    SpriteClips[4].w = 150;
    SpriteClips[4].h = 205;

    SpriteClips[5].x = 300;
    SpriteClips[5].y = 0;
    SpriteClips[5].w = 150;
    SpriteClips[5].h = 205;

    SpriteClips[6].x = 0;
    SpriteClips[6].y = 0;
    SpriteClips[6].w = 1;
    SpriteClips[6].h = 1;
    //concangua
    SpriteClips[7].x = 0;
    SpriteClips[7].y = 0;
    SpriteClips[7].w = 52/2;
    SpriteClips[7].h = 100/2;

    SpriteClips[8].x = 52/2;
    SpriteClips[8].y = 0;
    SpriteClips[8].w = 52/2;
    SpriteClips[8].h = 100/2;

    SpriteClips[9].x = 104/2;
    SpriteClips[9].y = 0;
    SpriteClips[9].w = 56/2;
    SpriteClips[9].h = 100/2;
    //conbachtuoc
    SpriteClips[10].x = 0;
    SpriteClips[10].y = 0;
    SpriteClips[10].w = 116/2;
    SpriteClips[10].h = 130/2;

    SpriteClips[11].x = 116/2;
    SpriteClips[11].y = 0;
    SpriteClips[11].w = 117/2;
    SpriteClips[11].h = 130/2;

    SpriteClips[12].x = 233/2;
    SpriteClips[12].y = 0;
    SpriteClips[12].w = 115/2;
    SpriteClips[12].h = 130/2;
    // ca ke soc
    SpriteClips[13].x = 0;
    SpriteClips[13].y = 0;
    SpriteClips[13].w = 208/2;
    SpriteClips[13].h = 160/2;

    SpriteClips[14].x = 208/2;
    SpriteClips[14].y = 0;
    SpriteClips[14].w = 210/2;
    SpriteClips[14].h = 160/2;

    SpriteClips[15].x = 418/2;
    SpriteClips[15].y = 0;
    SpriteClips[15].w = 204/2;
    SpriteClips[15].h = 160/2;
    //ca hong
    SpriteClips[16].x = 0;
    SpriteClips[16].y = 0;
    SpriteClips[16].w = 391/2;
    SpriteClips[16].h = 270/2;

    SpriteClips[17].x = 391/2;
    SpriteClips[17].y = 0;
    SpriteClips[17].w = 354/2;
    SpriteClips[17].h = 270/2;

    SpriteClips[18].x = 745/2;
    SpriteClips[18].y = 0;
    SpriteClips[18].w = 337/2;
    SpriteClips[18].h = 270/2;

    //ca noc
    SpriteClips[19].x = 0;
    SpriteClips[19].y = 0;
    SpriteClips[19].w = 261/2;
    SpriteClips[19].h = 200/2;

    SpriteClips[20].x = 261/2;
    SpriteClips[20].y = 0;
    SpriteClips[20].w = 240/2;
    SpriteClips[20].h = 200/2;

    SpriteClips[21].x = 501/2;
    SpriteClips[21].y = 0;
    SpriteClips[21].w = 239/2;
    SpriteClips[21].h = 200/2;

    //ca he
    SpriteClips[22].x = 0;
    SpriteClips[22].y = 0;
    SpriteClips[22].w = 429/2;
    SpriteClips[22].h = 240/2;

    SpriteClips[23].x = 429/2;
    SpriteClips[23].y = 0;
    SpriteClips[23].w = 397/2;
    SpriteClips[23].h = 240/2;

    SpriteClips[24].x = 826/2;
    SpriteClips[24].y = 0;
    SpriteClips[24].w = 384/2;
    SpriteClips[24].h = 240/2;

    ca conca;
    cacon camini[3];
    cacon cakesoc[3];
    srand(time(0));
    int i = 0;
    while(i<=2)
    {
        cakesoc[i].sizeca = 2;
        cakesoc[i].spriteclips = 13;
        int r = rand()%2;
        if(r == 0) {
            camini[i].direction = true;
            cakesoc[i].direction = true;
            camini[i].toadox = 0;
            cakesoc[i].toadox =0;
        }
        else{
            camini[i].toadox = SCREEN_WIDTH;
            cakesoc[i].toadox = SCREEN_WIDTH;
        }
        int rd = rand()%200;
        camini[i].toadoy = rd +150 ;
        cakesoc[i].toadoy = rd + 250;

        camini[i].load_anh("caminileft.png","caminiright.png",camini[i].direction, gRenderer);
        cakesoc[i].load_anh("cakesocleft.png", "cakesocright.png", cakesoc[i].direction, gRenderer);
        i++;
    }

    conca.load_anh("bachtuoc.png","bachtuocleft.png", gRenderer);
    conca.current_clip = &SpriteClips[10];
    SDL_Texture *background = loadBackground(gRenderer);
    while(!quit){
        while(SDL_PollEvent(&e)!=0){
            if(e.type == SDL_QUIT)  quit = true;
        }
        conca.handle_event(e, SpriteClips);
        conca.move(e,SpriteClips);
        for(int i=0;i<=2;i++){
            camini[i].move(camini[i].direction, SpriteClips);
            cakesoc[i].move(cakesoc[i].direction,SpriteClips);
            if(conca.check_collision(camini[i])){
                if(conca.size_ca >= camini[i].sizeca){
                    score += 10;
                    cout << score << endl;
                    camini[i].toadoy = rand()%200 + 100;
                    int ran = rand()%2;
                    if(ran == 0){
                        camini[i].direction = true;
                        camini[i].toadox = 0;
                        camini[i].mTexture = camini[i].rightTexture;
                    }
                    else{
                        camini[i].direction = false;
                        camini[i].toadox = SCREEN_WIDTH;
                        camini[i].mTexture = camini[i].leftTexture;
                    }
                }
                else{
                    quit = true;
                    cout << "Your score is " << score;
                }
            }
            if(conca.check_collision(cakesoc[i])){
                    if(conca.size_ca >= cakesoc[i].sizeca){
                        score += 20;
                        cout << score << endl;
                        cakesoc[i].toadoy = rand()%400;
                        int ran = rand()%2;
                        if(ran == 0){
                            cakesoc[i].direction = true;
                            cakesoc[i].toadox = 0;
                            cakesoc[i].mTexture = cakesoc[i].rightTexture;
                        }
                        else{
                            cakesoc[i].direction = false;
                            cakesoc[i].toadox = SCREEN_WIDTH;
                            cakesoc[i].mTexture = cakesoc[i].leftTexture;
                        }
                    }
                    else{
                        quit = true;
                        cout << "Your score is " << score;
                    }
                }
        }
        if(score == 100){
            conca.load_anh("canocright.png","canocleft.png", gRenderer);
            conca.spriteclips = 19;
            conca.size_ca = 2;
        }
        SDL_RenderClear(gRenderer);
        renderBackground(background, gRenderer);
        for(int i=0;i<=2;i++){
            camini[i].render(gRenderer);
            cakesoc[i].render(gRenderer);
        }
        conca.render_ca(gRenderer);
        SDL_RenderPresent(gRenderer);
    }
    TTF_Quit();
}
