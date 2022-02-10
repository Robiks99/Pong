#include"Game.h"


Game::Game(){}
Game::~Game(){}
Player* player;
Ball* ball;
Enemy* enemy;
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }

        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
            printf("Subsystem initialized.\n");
        

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window)printf("Window initialized.\n");

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer){
            printf("Renderer initialized.\n");
        }
        player = new Player(renderer, window, 30,height/2,60,6);
        enemy = new Enemy(renderer, window, width-30,height/2,60,6);
        ball = new Ball(renderer, window);
        //rectArray[] = {ball.GetRect(), player->getRect(), enemy->getRect()}
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    
}
void Game::handleEvents(){
    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0  ){
        //User requests quit
        if( event.type == SDL_QUIT )
        {
            isRunning = false;
        }
       
        player->move(event);
    }
    enemy->move(ball);

}
void Game::update(){
    player->update();
    ball->update();
    enemy->update();

    ball->checkEntityCollision(player->rect);
    ball->checkEntityCollision(enemy->rect);
    ball->checkYWallCollision();
    ball->checkXWallCollision();
    player->checkYWallCollision();
    enemy->checkYWallCollision();
}
void Game::render(){
    SDL_RenderClear(renderer);
    player->render();
    ball->render();
    enemy->render();
    
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    printf("Game Cleaned");
}


