#include"InterfaceElement.h"

InterfaceElement::InterfaceElement(SDL_Renderer* Renderer, const char* Font, int XPos, int YPos){
    font = TTF_OpenFont(Font,64);
    renderer = Renderer;
    rect.x = XPos;
    rect.y = YPos;
    score = 0;
    text = TTF_RenderText_Solid(font,"0",textColor);
    texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_FreeSurface(text);
    
}
InterfaceElement::InterfaceElement(SDL_Renderer* Renderer, const char* Font, const char* Text, int XPos, int YPos){
    font = TTF_OpenFont(Font,64);
    renderer = Renderer;
    rect.x = XPos;
    rect.y = YPos;
    score = 0;
    text = TTF_RenderText_Solid(font,Text,textColor);
    texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_FreeSurface(text);
}

InterfaceElement::~InterfaceElement(){
}
void InterfaceElement::update(){
    score++;
    strScore = std::to_string(score);
    SDL_DestroyTexture(texture);
    text = TTF_RenderText_Solid(font, strScore.c_str(),textColor);
    texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_QueryTexture(texture,NULL,NULL,&rect.w,&rect.h);
    SDL_FreeSurface(text);
}
void InterfaceElement::render(){
    SDL_RenderCopy(renderer, texture, NULL, &rect);
    

}