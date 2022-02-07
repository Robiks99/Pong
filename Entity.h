#ifndef Entity_h
#define Entity_h

#include<SDL2/SDL.h>
#include<stdio.h>

class Entity{
public:
    Entity(SDL_Renderer* renderer);
    Entity(SDL_Renderer* renderer,int XPos, int YPos, int Height, int Width);
    ~Entity();

    void update();
    void render();

    int xPos,yPos;
    int xVel = 0, yVel = 0;
    int speed = 1;
private:
    
    int height, width;
    SDL_Rect rect;
    SDL_Renderer* renderer;
};

#endif