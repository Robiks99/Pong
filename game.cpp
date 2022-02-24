#include"Game.h"

Game::Game(){}
Game::~Game(){}

#pragma region Game
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    
    if(fullscreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
        
        //Initialize SDL
        if(SDL_Init(SDL_INIT_EVERYTHING) == 0){//Initialize SDL
            printf("Subsystem initialized.\n");
        

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);//Initialize Window
        if(window){
            printf("Window initialized.\n");
        }

        renderer = SDL_CreateRenderer(window,-1,0);//Initialize Renderer
        if(renderer){
            printf("Renderer initialized.\n");
        }
        SDL_SetWindowBordered( window, SDL_FALSE );//Disable window top bar

        //Initialize objects
        player = new Player(renderer, window, 30,height/2,60,6);
        enemy = new Enemy(renderer, window, width-30,height/2,60,6);
        ball = new Ball(renderer, window);
        //rectArray[] = {ball.GetRect(), player->getRect(), enemy->getRect()}
        isRunning = true;
        isMenu = false;
        inputDelay = SDL_GetTicks64();
    }
    else{
        isRunning = false;
        return;
    }
    
    //Initialize SDL_ttf
    if( TTF_Init() == -1 ){
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }
    //Initilize interface objects
    //game
    playerScore = new InterfaceElement(renderer, "Retro_Gaming.ttf", 80, 40);
    enemyScore = new InterfaceElement(renderer, "Retro_Gaming.ttf", width-140, 40);
    //menu
    resume = new InterfaceElement(renderer, "Retro_Gaming.ttf","Resume",220, 50);
    leave = new InterfaceElement(renderer, "Retro_Gaming.ttf","Exit",220, 120);
    selector = new Selector(renderer, window,190,0, 20, 20);
}
void Game::handleEvents(){
    SDL_Event event;
    while( SDL_PollEvent( &event ) != 0  ){
        if( event.type == SDL_QUIT )//User requests quit
        {
            isRunning = false;
            isMenu = false;
        }
        if(event.key.keysym.sym == SDLK_ESCAPE){
            if(200 < SDL_GetTicks64() - inputDelay){
                isMenu = true;
                inputDelay = SDL_GetTicks64();
           }
        }
       
        player->move(event);
    }
    enemy->move(ball);

}
void Game::update(){
    //update entities
    dT = (SDL_GetTicks() - startTicks)/1000.f;
    startTicks = SDL_GetTicks();
    player->update(dT);
    ball->update(dT);
    enemy->update(dT);
    
    ball->moveDelay();
    //check collisions
    ball->checkEntityCollision(player->rect);
    ball->checkEntityCollision(enemy->rect);
    ball->checkYWallCollision();
    //ball->checkXWallCollision();
    player->checkYWallCollision();
    enemy->checkYWallCollision();
    //update score
    if(ball->checkLeftPlayerGoal()){
        enemyScore->update();
    }
    if(ball->checkRightPlayerGoal()){
        playerScore->update();
    }
    
    
}
void Game::render(){
    SDL_RenderClear(renderer);
    
    enemyScore->render();
    playerScore->render();
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
#pragma endregion Game

#pragma region Menu
void Game::menuHandleEvents(){
    SDL_Event event;
    
    while( SDL_PollEvent( &event ) != 0  ){
        if( event.type == SDL_QUIT )//User requests quit
        {
            isRunning = false;
            isMenu = false;
        }
        if(event.key.keysym.sym == SDLK_ESCAPE){
           if(200 < SDL_GetTicks64() - inputDelay){
                isMenu = false;
                startTicks = SDL_GetTicks64();
                inputDelay = startTicks;
           }
        }
        if(event.key.keysym.sym == SDLK_RETURN){
            switch (selectorState)
            {
            case 0:
                isMenu = false;
                startTicks = SDL_GetTicks64();
                break;
            
            case 1:
                isRunning = false;
                isMenu = false;
                break;
            }
        }
        selector->handleEvents(event);
    }
}
void Game::menuUpdate(){
    selectorState = selector->getSelectorState();
    if(selectorState == 0)selector->yPos = resume->rect.y+30;
    if(selectorState == 1)selector->yPos = leave->rect.y+30;
    selector->update();
}
void Game::menuRender(){
     SDL_RenderClear(renderer);
    
     enemyScore->render();
    playerScore->render();
    player->render();
    ball->render();
    enemy->render(); 
    resume->render();
    leave->render();
    selector->render();
    
    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
}
#pragma endregion Menu