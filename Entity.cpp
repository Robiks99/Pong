#include"Entity.h"

Entity::Entity(SDL_Renderer* Renderer, SDL_Window* Window){
    //Initializing variables
    SDL_GetWindowSize(Window, &windowWidth, &windowHeight);
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
Entity::Entity(SDL_Renderer* Renderer,SDL_Window* Window, int XPos, int YPos, int Height, int Width){
    //Initializing variables
    SDL_GetWindowSize(Window, &windowWidth, &windowHeight);
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
Entity::~Entity(){
    
}

void Entity::render(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    SDL_RenderDrawRect(renderer, &rect);
    
}

void Entity::update(){
    xPos += xVel;
    yPos += yVel;
    rect.x = xPos;
    rect.y = yPos;
}

void Entity::checkYWallCollision(){
    if(yPos < 0){
        yPos += speed;
    }
    if(yPos+height > windowHeight){
        yPos -= speed;
    }
}
