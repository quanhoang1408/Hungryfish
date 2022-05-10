#include <iostream>
#include <SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

SDL_Window* gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
void initSDL();
class cacon;
class ca{
    public:
        int size_ca =1, spriteclips = 10;
        void load_anh(string pathright, string pathleft);
        void handle_event(SDL_Event &e, SDL_Rect SpriteClips[]);
        void move(SDL_Event &e, SDL_Rect SpriteClips[]);
        void render_ca();
        bool check_collision(cacon camini);
        int toadox=SCREEN_WIDTH/2 -50;
        int toadoy=0;
        int velx=0, vely=0;
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
class cacon{
    public:
        int sizeca = 1, spriteclips = 7;
        int toadox = SCREEN_WIDTH/2 , toadoy = SCREEN_HEIGHT/2;
        int frame =0;
        int speed = 0;
        int f=0;
        SDL_Rect* current_clip;
        SDL_Texture* mTexture;
        SDL_Texture* leftTexture;
        SDL_Texture* rightTexture;
        bool direction = false;
        void load_anh(string pathleft, string pathright, bool direction);
        void move(bool direction,SDL_Rect SpriteClips[]);
        void render();
};
bool ca::check_collision(cacon camini){
    if(toadox + current_clip->w - 60 <= camini.toadox){
        return false;
    }
    if(toadox >= camini.toadox+camini.current_clip->w - 20){
        return false;
    }
    if(toadoy + current_clip->h - 30 <= camini.toadoy){
        return false;
    }
    if(toadoy >= camini.toadoy + camini.current_clip->h ){
        return false;
    }
    return true;
}
void cacon::load_anh(string pathleft, string pathright, bool direction)
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

void cacon::render()
{
    SDL_Rect quadrad = {toadox, toadoy, current_clip->w, current_clip->h};
    SDL_RenderCopy(gRenderer, mTexture, current_clip, &quadrad);
}

void ca::load_anh(string pathright, string pathleft){
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
void ca::render_ca(){
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
 SDL_Texture *loadBackground(){
    SDL_Surface *loadsurface = IMG_Load("background.png");
    SDL_Texture *background = SDL_CreateTextureFromSurface(gRenderer,loadsurface);
    SDL_FreeSurface(loadsurface);
    return background;
}
void renderBackground(SDL_Texture *background){
    SDL_RenderCopy(gRenderer,background,nullptr,nullptr);
}
void initSDL()
{
    gWindow = SDL_CreateWindow("Big_game_test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
}
int main(int argc, char* argv[])
{
    initSDL();
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
    SpriteClips[7].w = 52;
    SpriteClips[7].h = 100;

    SpriteClips[8].x = 52;
    SpriteClips[8].y = 0;
    SpriteClips[8].w = 52;
    SpriteClips[8].h = 100;

    SpriteClips[9].x = 104;
    SpriteClips[9].y = 0;
    SpriteClips[9].w = 56;
    SpriteClips[9].h = 100;
    //conbachtuoc
    SpriteClips[10].x = 0;
    SpriteClips[10].y = 0;
    SpriteClips[10].w = 116;
    SpriteClips[10].h = 130;

    SpriteClips[11].x = 116;
    SpriteClips[11].y = 0;
    SpriteClips[11].w = 117;
    SpriteClips[11].h = 130;

    SpriteClips[12].x = 233;
    SpriteClips[12].y = 0;
    SpriteClips[12].w = 115;
    SpriteClips[12].h = 130;
    // ca ke soc
    SpriteClips[13].x = 0;
    SpriteClips[13].y = 0;
    SpriteClips[13].w = 208;
    SpriteClips[13].h = 160;

    SpriteClips[14].x = 208;
    SpriteClips[14].y = 0;
    SpriteClips[14].w = 210;
    SpriteClips[14].h = 160;

    SpriteClips[15].x = 418;
    SpriteClips[15].y = 0;
    SpriteClips[15].w = 204;
    SpriteClips[15].h = 160;
    //ca hong
    SpriteClips[16].x = 0;
    SpriteClips[16].y = 0;
    SpriteClips[16].w = 391;
    SpriteClips[16].h = 270;

    SpriteClips[17].x = 391;
    SpriteClips[17].y = 0;
    SpriteClips[17].w = 354;
    SpriteClips[17].h = 270;

    SpriteClips[18].x = 745;
    SpriteClips[18].y = 0;
    SpriteClips[18].w = 337;
    SpriteClips[18].h = 270;

    //ca noc
    SpriteClips[19].x = 0;
    SpriteClips[19].y = 0;
    SpriteClips[19].w = 261;
    SpriteClips[19].h = 200;

    SpriteClips[20].x = 261;
    SpriteClips[20].y = 0;
    SpriteClips[20].w = 240;
    SpriteClips[20].h = 200;

    SpriteClips[21].x = 501;
    SpriteClips[21].y = 0;
    SpriteClips[21].w = 239;
    SpriteClips[21].h = 200;

    //ca he
    SpriteClips[22].x = 0;
    SpriteClips[22].y = 0;
    SpriteClips[22].w = 429;
    SpriteClips[22].h = 240;

    SpriteClips[23].x = 429;
    SpriteClips[23].y = 0;
    SpriteClips[23].w = 397;
    SpriteClips[23].h = 240;

    SpriteClips[24].x = 826;
    SpriteClips[24].y = 0;
    SpriteClips[24].w = 384;
    SpriteClips[24].h = 240;

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

        camini[i].load_anh("caminileft.png","caminiright.png",camini[i].direction);
        cakesoc[i].load_anh("cakesocleft.png", "cakesocright.png", cakesoc[i].direction);
        i++;
    }

    conca.load_anh("bachtuoc.png","bachtuocleft.png");
    conca.current_clip = &SpriteClips[10];
    SDL_Texture *background = loadBackground();
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
            conca.load_anh("canocright.png","canocleft.png");
            conca.spriteclips = 19;
            conca.size_ca = 2;
        }
        SDL_RenderClear(gRenderer);
        renderBackground(background);
        for(int i=0;i<=2;i++){
            camini[i].render();
            cakesoc[i].render();
        }
        conca.render_ca();
        SDL_RenderPresent(gRenderer);
    }
    TTF_Quit();
}
