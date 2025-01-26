#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader{
    public:
        Shader(const char* vertexPath, const char* fragmentPath);
};

#endif