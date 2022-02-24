#include"Enemy.h"
Enemy::Enemy(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer, Window){
    speed = 80;
}
Enemy::Enemy(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width) :
Entity(Renderer, Window, XPos, YPos, Height, Width){
    speed = 80;

}

void Enemy::move(Ball* Ball){
    if(Ball->xVel < 0){// if ball is going toward player
        if((yPos-(height/2)) > ((windowHeight/2)+32)){
            yVel = -1;
            return;
        }
        if((yPos-(height/2)) < ((windowHeight/2)-32)){
            yVel = 1;
            return;
        }
        yVel = 0;
        return;
    }
    if(Ball->xVel > 0){//if ball is going toward enemy
        if((Ball->yPos+(Ball->height/2) + 16) < yPos + height/2){
            yVel = -1;
            return;
        }
        if((Ball->yPos+(Ball->height/2) - 16) > yPos + height/2){
            yVel = 1;
            return;
        }
        yVel = 0;
        return;
    }
}