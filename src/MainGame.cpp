#include "MainGame.h"

using namespace Mido;

static void sdl_failure(const std::string& error){
    std::cerr << error << "\n" << SDL_GetError();
    
    SDL_Quit();
    std::exit(-1);
}

MainGame::MainGame()
    : m_renderer{nullptr},
      m_window{nullptr}, 
      m_height{constants::DEFAULT_HEIGHT},
      m_width{constants::DEFAULT_WIDTH}
{
    
}

void MainGame::run(){
    initSystems();
    gameLoop();
}

void MainGame::initSystems(){
    // initalize SDL
    if( SDL_Init(SDL_INIT_EVERYTHING) < 0){
        sdl_failure("SDL could not initialize! SDL_Error:");
    }

    m_window = SDL_CreateWindow("MidoTracer (WIP!)", 
                                SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED,
                                m_width, m_height, 
                                SDL_WINDOW_SHOWN);

    if( m_window == NULL ){
        sdl_failure("SDL could not create a window! SDL_Error:");
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    if( m_renderer == NULL ){
        sdl_failure("SDL could not create a Render! SDL_Error:");
    }

    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(m_renderer);
    SDL_RenderClear(m_renderer);

    m_gameState = GameState::PLAY;
}

void MainGame::gameLoop(){
    while(m_gameState != GameState::QUIT){   
        // input
        processInput();

        // render
        SDL_RenderDrawPoint(m_renderer, 400, 300);
        SDL_RenderClear(m_renderer);
        // update
    }
}

void MainGame::processInput(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch(e.type){
            case SDL_QUIT:
                m_gameState = GameState::QUIT;
                break;
        }
    }
}

MainGame::~MainGame(){
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();    
}

