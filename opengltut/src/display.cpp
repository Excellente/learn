#include "display.hpp"

Display::Display(int width, int height, const std::string& title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    glcontext = SDL_GL_CreateContext(win);
    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "Glew failed to initilize" << std::endl;
    }
    win_isClosed = false;
}

void Display::clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool    Display::isClosed()
{
    return (win_isClosed);
}

Display::~Display(){
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void    Display::update()
{
    SDL_Event e;

    SDL_GL_SwapWindow(win);
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            win_isClosed = true;
    }
}