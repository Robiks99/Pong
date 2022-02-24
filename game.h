#ifndef Game_h
#define Game_h

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<stdio.h>

#include"Player.h"
#include"Ball.h" 
#include"Enemy.h"
#include"InterfaceElement.h"
#include"Selector.h"

class Game{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    //Game loop
    void handleEvents();
    void update();
    void render();
    void clean();
    //Menu loop
    void menuHandleEvents();
    void menuUpdate();
    void menuRender();
    //FPS cap
    void getTicks(){dT = (SDL_GetTicks() - startTicks)/1000.f;}
    void setTicks(){startTicks = SDL_GetTicks();}
    
    void setIsMenu(){isMenu = false;}
    //return game state
    bool running(){return isRunning;}
    bool menu(){return isMenu;}


    
private:
    bool isRunning, isMenu;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Uint32 startTicks = 0;
    float dT;
    Uint32 inputDelay;
    int selectorState = 0;
    //SDL_rect rectArray[];
    Player* player;
    Ball* ball;
    Enemy* enemy;
    InterfaceElement* playerScore;
    InterfaceElement* enemyScore;
    InterfaceElement* resume;
    InterfaceElement* leave;
    Selector* selector;
};

#endif