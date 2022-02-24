#ifndef InterfaceElement_h
#define InterfaceElement_h

#include<sstream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>


class InterfaceElement{
public:
    InterfaceElement(SDL_Renderer* Renderer, const char* Font, int XPos, int YPos);
    InterfaceElement(SDL_Renderer* Renderer, const char* Font, const char* Text, int XPos, int YPos);
    ~InterfaceElement();

    void update();
    void render();
    SDL_Rect rect;
private:
    SDL_Surface* text;
    SDL_Texture* texture;
    SDL_Color textColor = { 0, 0, 0 };
    TTF_Font* font;
    SDL_Renderer* renderer;
    int score;
    int height, width;
    std::string strScore;
};

#endif