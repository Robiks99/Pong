#include"Ball.h"
Ball::Ball(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer, Window){
    
    SDL_GetWindowSize(Window, &windowWidth, &windowHeight);

    xPos = (windowWidth/2)-(width/2);
    yPos = (windowHeight/2)-(height/2);  
    
    xVel = -3;
    yVel = -1;
}



void Ball::move(){

}
void Ball::checkXWallCollision(){
    if(xPos < 0 || (xPos+width) > windowWidth){
        xVel *= -1;
    }
}
void Ball::checkYWallCollision(){
    if(yPos < 0 || yPos+height > windowHeight){
        yVel *= -1;
    }
}

void Ball::checkEntityCollision(SDL_Rect Rect){
    if( (rect.y+rect.h) <= Rect.y )
    {
        return;
    }

    if( rect.y >= Rect.y+Rect.h )
    {
        return;
    }

    if( (rect.x+rect.w) <= Rect.x )
    {
        return;
    }

    if( rect.x >= (Rect.x+Rect.w) )
    {
        return;
    }
    xVel *= -1;
    return;
}