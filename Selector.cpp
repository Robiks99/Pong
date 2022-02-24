#include"Selector.h"

Selector::Selector(SDL_Renderer* Renderer, SDL_Window* Window, int XPos, int YPos, int Height, int Width) :
Entity(Renderer, Window, XPos, YPos, Height, Width){

}

void Selector::handleEvents(SDL_Event Event){
    event = Event;
    if( event.type == SDL_KEYDOWN)
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_w:  selectorState -= 1; break;
            case SDLK_s:  selectorState += 1; break;
        }
        if(selectorState > 1){selectorState = 0;}
        if(selectorState < 0){selectorState = 1;}
    }
}

void Selector::update(){
    xPos += (xVel*speed);
    yPos += (yVel*speed);
    rect.x = xPos;
    rect.y = yPos;
}

void Selector::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}