#include "MainGame.h"

using namespace Mido;

static void sdl_failure(const std::string& error)
{
    std::cerr << error << "\n" << SDL_GetError();
    
    SDL_Quit();
    std::exit(-1);
}

MainGame::MainGame()
    : m_window{nullptr}, 
      m_height{constants::DEFAULT_HEIGHT},
      m_width{constants::DEFAULT_WIDTH}
{
    
}

void MainGame::run()
{
    initSystems();
    gameLoop();
}

void MainGame::initSystems()
{
    // initalize SDL
    if( SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        sdl_failure("SDL could not initialize! SDL_Error:");
    }

    m_window = SDL_CreateWindow("MidoTracer (WIP!)", 
                                SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED,
                                m_width, m_height, 
                                SDL_WINDOW_OPENGL);

    if( m_window == NULL )
    {
        sdl_failure("SDL could not create a window! SDL_Error:");
    }

    // load GL library (default)
    if(SDL_GL_LoadLibrary(nullptr))
    {
            sdl_failure("Failed to load GL Library! SDL_Error:");
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 
                        constants::DEFAULT_GL_MAJOR_CVERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 
                        constants::DEFAULT_GL_MINOR_CVERSION);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    m_glContext = SDL_GL_CreateContext(m_window);
    if(!m_glContext)
    {
        sdl_failure("Failed to create GL Context! SDL_Error:");
    }

    if(gladLoadGLLoader(SDL_GL_GetProcAddress))
    {
        sdl_failure("Failed to Load GL Loader! SDL_Error:");
    }

    // Use v-sync
    SDL_GL_SetSwapInterval(1);

    int w,h;
    SDL_GetWindowSize(m_window, &w, &h);
    
    glViewport(0, 0, w, h);
    glClearColor(0.0f, 0.5f, 1.0f, 0.0f);

    m_gameState = GameState::PLAY;
}

void MainGame::gameLoop()
{
    while(m_gameState != GameState::QUIT)
    {   
        // input
        processInput();

        // render
        glClear(GL_COLOR_BUFFER_BIT);
        // update
        SDL_GL_SwapWindow(m_window);
    }
}

void MainGame::processInput()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT:
                m_gameState = GameState::QUIT;
                break;
        }
    }
}

MainGame::~MainGame()
{
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

