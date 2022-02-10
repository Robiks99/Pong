#ifndef Player_h
#define Player_h

#include"Entity.h"
class Player: public Entity{
public:
    Player(SDL_Renderer* Renderer, SDL_Window* Window);
    Player(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width);
    ~Player();

    void move(SDL_Event Event);
private:
    SDL_Event event;
};

#endif