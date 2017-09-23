#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>
#include "SDL.h"
#include "glew.h"

class Display {
    public:
        void update();
        bool isClosed();
        virtual ~Display();
        void clear(float r, float g, float b, float a);
        Display(int width, int height, const std::string& title);
    private:
        bool win_isClosed;
        SDL_Window *win;
        SDL_GLContext glcontext;
        // Display(const Display& other){}
        // Display& operator=(const Display& other){}
};

#endif