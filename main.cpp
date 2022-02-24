#define SDL_MAIN_HANDLED
#include"Game.h"

int main(int argc, const char* argv[]){
    Game *game = new Game();
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;


    game->init("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while(game->running()){
         while(game->menu()){
            frameStart = SDL_GetTicks();
            
            game->menuHandleEvents();
            game->menuUpdate();
            game->menuRender();

            frameTime = SDL_GetTicks() - frameStart;
            if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
        }
        frameStart = SDL_GetTicks();


        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
        
    }

    game->clean();

    
    return 0;
}