#ifndef Entity_h
#define Entity_h

#include<SDL2/SDL.h>
#include<stdio.h>

class Entity{
public:
    Entity(SDL_Renderer* renderer, SDL_Window* Window);
    Entity(SDL_Renderer* renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width);
    ~Entity();

    void update();
    void render();

    void checkYWallCollision();

    
    int xPos,yPos;
    int height, width;
    int xVel = 0, yVel = 0;
    int speed = 1;
    int windowHeight, windowWidth;
    SDL_Rect rect;
    SDL_Window* window;
private:
    SDL_Renderer* renderer;
};

#endif