#include"Ball.h"
Ball::Ball(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer){
    
    SDL_GetWindowSize(Window, &windowWidth, &windowHeight);

    xPos = (windowWidth/2)-(width/2);
    yPos = (windowHeight/2)-(height/2);  
    

}



void Ball::move(){

}