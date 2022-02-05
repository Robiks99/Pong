#include"Game.h"
Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;

    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
            printf("Subsystem initialized.\n");
        

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window)printf("Window initialized.\n");

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer,128,128,128,255);
            printf("Renderer initialized.\n");
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
}
void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}
void Game::update(){

}
void Game::render(){
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    printf("Game Cleaned");
}



