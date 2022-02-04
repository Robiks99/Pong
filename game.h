#ifndef game_h
#define game_h

#include <stdio.h>
#include <SDL2/SDL.h>

class Game{
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscrean);

    void handleEvents();
    void update();
    void reder();
    void clean();

    bool running() {return isRunning;}

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;

};


#endif