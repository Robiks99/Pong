#ifndef Enemy_h
#define Enemy_h

#include"Entity.h"
#include"Ball.h"

class Enemy : public Entity{
public:
    Enemy(SDL_Renderer* Renderer, SDL_Window* Window);
    Enemy(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width);
    ~Enemy();

    void move(Ball* Ball);

};

#endif