#include"Player.h"

Player::Player(SDL_Renderer* Renderer, SDL_Window* Window) : Entity(Renderer, Window){
    speed = 80;
}
Player::Player(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width) : 
Entity(Renderer, Window, XPos, YPos, Height, Width){
    speed = 80;
}
Player::~Player(){

}

void Player::move(SDL_Event Event){
    event = Event;
    if( event.type == SDL_KEYDOWN)
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_w:  yVel = -1; break;
            case SDLK_s:  yVel = 1; break;
        }
        return;
    }
    if( event.type == SDL_KEYUP){
        switch( event.key.keysym.sym )
        {
            case SDLK_w: yVel = 0; break;
            case SDLK_s: yVel = 0; break;
        }
        return;
    }


}