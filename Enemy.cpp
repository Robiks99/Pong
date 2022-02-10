#include"Enemy.h"
Enemy::Enemy(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer, Window){

}
Enemy::Enemy(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width) :
 Entity(Renderer, Window, XPos, YPos, Height, Width){
     

}

void Enemy::move(Ball* Ball){
    if(Ball->xVel < 0){
        if((yPos-(height/2)) > ((windowHeight/2)+32)){
            yVel = -speed;
            return;
        }
        if((yPos-(height/2)) < ((windowHeight/2)-32)){
            yVel = speed;
            return;
        }
        yVel = 0;
        return;
    }
    if(Ball->xVel > 0){
        if(Ball->yPos < yPos){
            yVel = -speed;
        }
        if(Ball->yPos > yPos){
            yVel = speed;
        }
    }
}