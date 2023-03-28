#ifndef _MAIN_GAME_H
#define _MAIN_GAME_H

#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <SDL2/SDL_opengl.h>
#include <iostream>
#include <string>

namespace Mido{
    
    enum class GameState {PLAY, QUIT};

    namespace constants{
        constexpr int DEFAULT_WIDTH             = 1280;
        constexpr int DEFAULT_HEIGHT            = 720;
        constexpr int DEFAULT_GL_MAJOR_CVERSION = 3;
        constexpr int DEFAULT_GL_MINOR_CVERSION = 1;
    }   

    class MainGame
    {
    public:
        MainGame();

        ~MainGame();

        void run();

        void gameLoop();

        void processInput();

    private:
        void initSystems(); 

        GameState       m_gameState;    
        SDL_Renderer   *m_renderer;
        SDL_Window     *m_window;
        int             m_height;
        int             m_width;
    };
}

#endif