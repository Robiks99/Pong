#include"game.h"

int main(int argc, const char* argv[]){
Game *game = new Game();

game->init("Pong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game->running()){

        game->handleEvents();
        game->update();
        game->reder();

    }

    game->clean();

    
    return 0;
}