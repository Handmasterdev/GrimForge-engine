#include "shader.h"

/*
 ____  _   _    _    ____  _____ ____  
/ ___|| | | |  / \  |  _ \| ____|  _ \ 
\___ \| |_| | / _ \ | | | |  _| | |_) |
 ___) |  _  |/ ___ \| |_| | |___|  _ < 
|____/|_| |_/_/   \_\____/|_____|_| \_\
*/



std::string Shader::get_file_contents(const char* filename) {
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file "<< std::endl;
        return "";
    }

    std::string contents;
    file.seekg(0, std::ios::end);
    contents.resize(file.tellg());
    file.seekg(0, std::ios::beg);
    file.read(&contents[0], contents.size());
    file.close();

    return contents;
}

Shader::Shader(const char* vertexPath, const char* fragmentPath){
    std::string vertexCode = get_file_contents(vertexPath);
    std::string fragmentCode = get_file_contents(fragmentPath);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);

    ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::activeShader(){
    glUseProgram(ID);
}

void Shader::deleteShader(){
    glDeleteProgram(ID);
}