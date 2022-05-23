#include <iostream>
#include <SDL.h>
//#include<SDL_ttf.h>
#include<SDL_image.h>
#include <stdlib.h>
#include <time.h>

#include "ca.h"
#include "cacon.h"
#include "SDL_utils.h"
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
void game(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);
void Intro(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);
int main(int argc, char* argv[])
{
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    init(gWindow, gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    Intro(gWindow, gRenderer);
    game(gWindow, gRenderer);
}
void game(SDL_Window *&gWindow, SDL_Renderer *&gRenderer){
    bool quit = false;
    SDL_Event e;
    int score = 0;
    SDL_Rect SpriteClips[30];
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
    SpriteClips[13].y = 10;
    SpriteClips[13].w = 208/2;
    SpriteClips[13].h = 65;

    SpriteClips[14].x = 208/2;
    SpriteClips[14].y = 10;
    SpriteClips[14].w = 210/2;
    SpriteClips[14].h = 65;

    SpriteClips[15].x = 418/2;
    SpriteClips[15].y = 10;
    SpriteClips[15].w = 204/2;
    SpriteClips[15].h = 65;
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
    SpriteClips[22].y = 12;
    SpriteClips[22].w = 210;
    SpriteClips[22].h = 112;

    SpriteClips[23].x = 226;
    SpriteClips[23].y = 12;
    SpriteClips[23].w = 407-226;
    SpriteClips[23].h = 112;

    SpriteClips[24].x = 420;
    SpriteClips[24].y = 12;
    SpriteClips[24].w = 180;
    SpriteClips[24].h = 112;

    SpriteClips[25].x = 0; //Shark
    SpriteClips[25].y = 0;
    SpriteClips[25].w = 500;
    SpriteClips[25].h = 286;

    SpriteClips[26].x = 500;
    SpriteClips[26].y = 0;
    SpriteClips[26].w = 445;
    SpriteClips[26].h = 286;

    SpriteClips[27].x = 945;
    SpriteClips[27].y = 0;
    SpriteClips[27].w = 455;
    SpriteClips[27].h = 286;

    ca conca;
    cacon camini[3];
    cacon cakesoc[3];
    cacon cahe[3];
    srand(time(0));
    int i = 0;

    while(i<=2)
    {
        cakesoc[i].sizeca = 2;
        cakesoc[i].spriteclips = 13;
        cahe[i].sizeca = 3;
        cahe[i].spriteclips = 22;
        camini[i].direction = rand()%2;
        cakesoc[i].direction = rand()%2;
        cahe[i].direction = rand()%2;
        if(camini[i].direction) camini[i].toadox = 0;
        else camini[i].toadox = SCREEN_WIDTH;
        if(cakesoc[i].direction) cakesoc[i].toadox =0;
        else cakesoc[i].toadox = SCREEN_WIDTH;
        if(cahe[i].direction) cahe[i].toadox =0;
        else cahe[i].toadox = SCREEN_WIDTH;
        camini[i].toadoy = rand()%200 +50 ;
        cakesoc[i].toadoy = rand()%200 + 200;
        cahe[i].toadoy = rand()%200 + 300;

        camini[i].load_anh("caminileft.png","caminiright.png",camini[i].direction, gRenderer);
        cakesoc[i].load_anh("cakesocleft.png", "cakesocright.png", cakesoc[i].direction, gRenderer);
        cahe[i].load_anh("caheleft.png","caheright.png",cahe[i].direction, gRenderer);
        i++;
    }

    conca.load_anh("bachtuoc.png","bachtuocleft.png", gRenderer);
    conca.current_clip = &SpriteClips[10];

    SDL_Texture *background = loadBackground(gRenderer, "background.png");
    SDL_Texture* shark_left = loadBackground(gRenderer, "shark.png");
    SDL_Texture* shark_right = loadBackground(gRenderer, "sharkthang.png");

    SDL_Texture* danger_sign = loadBackground(gRenderer, "fuckingdanger.png");

    int shark_frame = 1000, rep = 0;

    while(!quit){
        while(SDL_PollEvent(&e)!=0){
            if(e.type == SDL_QUIT)  quit = true;
        }
        conca.handle_event(e, SpriteClips);
        conca.move(e,SpriteClips);
        for(int i=0;i<=2;i++){
            camini[i].move(camini[i].direction, SpriteClips);
            cakesoc[i].move(cakesoc[i].direction,SpriteClips);
            cahe[i].move(cahe[i].direction, SpriteClips);
            if(conca.check_nearby(camini[i])){
                if(conca.toadox > camini[i].toadox && camini[i].direction == true){
                    camini[i].direction = false;
                    camini[i].mTexture = camini[i].leftTexture;
                }
                if(conca.toadox < camini[i].toadox && camini[i].direction == false){
                    camini[i].direction = true;
                    camini[i].mTexture = camini[i].rightTexture;
                }
            }
            if(conca.size_ca >= 2 && conca.check_nearby(cakesoc[i])){
                if(conca.toadox > cakesoc[i].toadox && cakesoc[i].direction == true){
                    cakesoc[i].direction = false;
                    cakesoc[i].mTexture = cakesoc[i].leftTexture;
                }
                if(conca.toadox < cakesoc[i].toadox && cakesoc[i].direction == false){
                    cakesoc[i].direction = true;
                    cakesoc[i].mTexture = cakesoc[i].rightTexture;
                }
            }
            if(conca.check_collision(camini[i])){
                score += 10;
                cout << score << endl;
                camini[i].toadoy = rand()%400 + 100;
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
                if(conca.check_collision(cahe[i])){
                    if(conca.size_ca >= cahe[i].sizeca){
                        score += 30;
                        cout << score << endl;
                        cahe[i].toadoy = rand()%500 + 50;
                        int ran = rand()%2;
                        if(ran == 0){
                            cahe[i].direction = true;
                            cahe[i].toadox = 0;
                            cahe[i].mTexture = cahe[i].rightTexture;
                        }
                        else{
                            cahe[i].direction = false;
                            cahe[i].toadox = SCREEN_WIDTH;
                            cahe[i].mTexture = cahe[i].leftTexture;
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
        if(300<=score && score <= 310){
            conca.load_anh("cahongright.png","cahongleft.png",gRenderer);
            conca.spriteclips = 16;
            conca.size_ca = 3;
        }

        //SDL_RenderClear(gRenderer);
        renderBackground(background, gRenderer);
        for(int i=0;i<=2;i++){
            camini[i].render(gRenderer);
            cakesoc[i].render(gRenderer);
            cahe[i].render(gRenderer);
        }
        if(score >= 30 && score <= 100)
        {
            if(rep == 100)
            {
                SDL_Rect current = SpriteClips[25];
                shark_frame = shark_incoming(shark_left, gRenderer, false, current, shark_frame);
            }
            else
            {
                SDL_Rect quadrad = {900, 200, 100, 100};
                SDL_RenderCopy(gRenderer, danger_sign, NULL, &quadrad);
                rep++;
            }
        }
        conca.render_ca(gRenderer);
        SDL_RenderPresent(gRenderer);
    }
}

void Intro(SDL_Window* &gWindow, SDL_Renderer* &gRenderer)
{
    SDL_Texture* ingamebg = loadBackground(gRenderer, "backgroundstart.png");
    SDL_Texture* play_button = loadBackground(gRenderer, "startgame.png");
    SDL_Texture *instruction = loadBackground(gRenderer, "instruction.png");

    SDL_Rect SpriteButs[3];
    //startgame
    SpriteButs[0].x = 0;
    SpriteButs[0].y = 0;
    SpriteButs[0].w = 300;
    SpriteButs[0].h = 85;

    SpriteButs[1].x = 300;
    SpriteButs[1].y = 0;
    SpriteButs[1].w = 300;
    SpriteButs[1].h = 85;
    //instruction
    SpriteButs[2].x = 0;
    SpriteButs[2].y = 0;
    SpriteButs[2].w = 247;
    SpriteButs[2].h = 76;

    SDL_Rect currentButton = SpriteButs[0];
    SDL_Rect currentInstruction = SpriteButs[2];

    bool start = false;
    bool inside = false;
    bool inside_instruction = false;
    bool quit = false;
    SDL_Event e;
    while(!quit && !start)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT) quit = true;
            if(e.type == SDL_MOUSEMOTION)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                inside = true;
                if(x < 330 || x > 630 || y < 200 || y > 285)
                {
                    inside = false;
                }
                if(inside == true) currentButton = SpriteButs[1];
                else currentButton = SpriteButs[0];
            }
            if(inside == true && e.type == SDL_MOUSEBUTTONDOWN) start = true;
        }

        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, ingamebg, NULL, NULL);
        SDL_Rect quadrad = {330,200,300,85};
        SDL_RenderCopy(gRenderer, play_button, &currentButton, &quadrad);
        SDL_RenderPresent(gRenderer);
    }
}

bool play_again(SDL_Window* &gWindow, SDL_Renderer* &gRenderer)
{
    SDL_Texture* game_over_bg = loadBackground(gRenderer, "backgroundend.png");
    SDL_Texture* play_again_button = loadBackground(gRenderer, "playagain.png");
    SDL_Texture* quit_button = loadBackground(gRenderer, "quit_game.png");

    SDL_Rect SpriteButs[4];

    SpriteButs[0].x = 33;
    SpriteButs[0].y = 23;
    SpriteButs[0].w = 110-33;
    SpriteButs[0].h = 64-23;

    SpriteButs[1].x = 129;
    SpriteButs[1].y = 23;
    SpriteButs[1].w = 208-129;
    SpriteButs[1].h = 170-23;

    SpriteButs[2].x = 22;
    SpriteButs[2].y = 27;
    SpriteButs[2].w = 197-22;
    SpriteButs[2].h = 62-27;

    SpriteButs[3].x = 230;
    SpriteButs[3].y = 25;
    SpriteButs[3].w = 410-230;
    SpriteButs[3].h = 69-25;

    SDL_Rect current_pab = SpriteButs[2];
    SDL_Rect current_gob = SpriteButs[0];

    bool inside_pa, inside_quit;
    bool quit = false;

    SDL_Event e;
    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT) quit = true;
            if(e.type == SDL_MOUSEMOTION)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                inside_pa = true;
                inside_quit = true;

                if(x < 430 || x > 580 || y < 200 || y > 280)
                {
                    inside_pa = false;
                }

                if(x < 430 || x > 580 || y < 300 || y > 380)
                {
                    inside_quit = false;
                }

                if(inside_pa == true) current_pab = SpriteButs[3];
                else current_pab = SpriteButs[2];

                if(inside_quit == true) current_gob = SpriteButs[1];
                else current_gob = SpriteButs[0];
            }
        }
        if(inside_pa == true && e.type == SDL_MOUSEBUTTONUP)
        {
            return true;
        }
        else if(inside_quit == true && e.type == SDL_MOUSEBUTTONUP)
        {
            return false;
        }

        SDL_RenderClear(gRenderer);
        SDL_RenderCopy(gRenderer, game_over_bg, NULL, NULL);
        SDL_Rect quit_rect = {430,200,150,85};
        SDL_Rect play_again_rect = {430,300,150,85};
        SDL_RenderCopy(gRenderer, play_again_button, &current_pab, &play_again_rect);
        SDL_RenderCopy(gRenderer, quit_button, &current_gob, &quit_rect);
        SDL_RenderPresent(renderer);
    }
}

