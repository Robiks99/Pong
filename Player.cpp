#include"Player.h"

Player::Player(SDL_Renderer* Renderer) : Entity(Renderer){

}

void Player::move(SDL_Event Event){
    event = Event;
    if( event.type == SDL_KEYDOWN)
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_UP:  yVel = -speed; break;
            case SDLK_DOWN:  yVel = speed; break;
            case SDLK_LEFT:  xVel = -speed; break;
            case SDLK_RIGHT:  xVel = speed; break;
        }
        return;
    }
    if( event.type == SDL_KEYUP){
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: yVel = 0; break;
            case SDLK_DOWN: yVel = 0; break;
            case SDLK_LEFT: xVel = 0; break;
            case SDLK_RIGHT: xVel = 0; break;
        }
        return;
    }


}