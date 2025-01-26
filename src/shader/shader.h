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
        GLuint ID;
        Shader(const char* vertexPath, const char* fragmentPath);

        std::string get_file_contents(const char* filename);

        void activeShader();
        void deleteShader();
};

#endif