#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <iostream>
#include "SDL.h"
#include "glew.h"

class Shader {
    public:
        virtual ~Shader();
        Shader(const std::string& filename);
    private:
        Shader(const Shader& other){}
        // Shader& operator=(const Shader& other){}
};

#endif