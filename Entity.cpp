#include"Entity.h"

Entity::Entity(SDL_Renderer* Renderer){
    //Initializing variables
    renderer = Renderer;
    xPos = 100;
    yPos = 100;
    height = 20;
    width = 20;
    //assigning variables to rect
    rect.x = xPos;
    rect.y = yPos;
    rect.h = height;
    rect.w = width;
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
    
}
Entity::Entity(SDL_Renderer* Renderer, int XPos, int YPos, int Height, int Width){
    //Initializing variables
    renderer = Renderer;
    xPos = XPos;
    yPos = YPos;
    height = Height;
    width = Width;
    //assigning variables to rect
    rect.x = xPos;
    rect.y = yPos;
    rect.h = height;
    rect.w = width;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void Entity::render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    SDL_RenderDrawRect(renderer, &rect);
    
}

void Entity::update(){
    rect.x = xPos;
    rect.y = yPos;
}
