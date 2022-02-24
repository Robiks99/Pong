#ifndef Selector_h
#define Selector_h

#include "Entity.h"

class Selector : public Entity{
public:
    Selector(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width);
    ~Selector();

    void handleEvents(SDL_Event Event);
    void update();
    void render();
    
    int getSelectorState(){return selectorState;}
private:
    int selectorState = 0;
    SDL_Event event;
};

#endif