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


private:
    int xPos,yPos;
    int height, width;
    SDL_Rect rect;
    SDL_Renderer* renderer;
};

#endif