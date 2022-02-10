#ifndef Ball_h
#define Ball_h

#include"Entity.h"

class Ball:public Entity{
public:
    Ball(SDL_Renderer* Renderer, SDL_Window* Window);
    Ball(SDL_Renderer* Renderer,SDL_Window* Window, int XPos, int YPos, int Height, int Width);
    ~Ball();

    void checkEntityCollision(SDL_Rect Rect);
    void move();
    void checkXWallCollision();
    void checkYWallCollision();

private:
    
};


#endif