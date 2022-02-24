#include"Ball.h"
Ball::Ball(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer, Window){
    
    SDL_GetWindowSize(Window, &windowWidth, &windowHeight);
    firstTick = SDL_GetTicks();

    xPos = (windowWidth/2)-(width/2);
    yPos = (windowHeight/2)-(height/2);  
    speed = 60;
    xVel = -3;
    yVel = -1;
}



void Ball::moveDelay(){
    
    currentTick = SDL_GetTicks();
    if(currentTick - firstTick > startDelay){
        speed = 60;
    }
}
bool Ball::checkLeftPlayerGoal(){
    if(xPos < 0) {
        xPos = (windowWidth/2)-(width/2);
        yPos = (windowHeight/2)-(height/2);
        firstTick = SDL_GetTicks();
        speed = 0;
        xVel = -3;
        yVel = 1;
        return true;
    }
    return false;
}
bool Ball::checkRightPlayerGoal(){
    if((xPos+width) > windowWidth){
        xPos = (windowWidth/2)-(width/2);
        yPos = (windowHeight/2)-(height/2);
        firstTick = SDL_GetTicks();
        speed = 0;
        xVel = 3;
        yVel = 1;
        return true;
    }
    return false;
}
void Ball::checkYWallCollision(){
    if(yPos < 0 || yPos+height > windowHeight){
        yVel *= -1;
    }
}

void Ball::checkEntityCollision(SDL_Rect Rect){
    if( (rect.y+rect.h) <= Rect.y )//check bottom ball side and top rect side
    {
        return;
    }

    if( rect.y >= Rect.y+Rect.h )//check top ball side and bottom rect side
    {
        return;
    }

    if( (rect.x+rect.w) <= Rect.x )//check right ball side and left rect side
    {
        return;
    }

    if( rect.x >= (Rect.x+Rect.w) )//check left ball side and right rect side
    {
        return;
    }
    xVel *= -1;
    yVel = (( (rect.y + (rect.h/2)) - (Rect.y+ (Rect.h/2)) ))/5;
    
    return;
}