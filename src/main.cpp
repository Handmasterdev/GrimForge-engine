#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

/*


   ▄▄▄▄███▄▄▄▄      ▄████████  ▄█  ███▄▄▄▄   
 ▄██▀▀▀███▀▀▀██▄   ███    ███ ███  ███▀▀▀██▄ 
 ███   ███   ███   ███    ███ ███▌ ███   ███ 
 ███   ███   ███   ███    ███ ███▌ ███   ███ 
 ███   ███   ███ ▀███████████ ███▌ ███   ███ 
 ███   ███   ███   ███    ███ ███  ███   ███ 
 ███   ███   ███   ███    ███ ███  ███   ███ 
  ▀█   ███   █▀    ███    █▀  █▀    ▀█   █▀  
                                             

*/

int main(){
    glfwInit();
    glfwWindowHint(GLFW_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 500, "GrimForge engine", NULL, NULL);

    if (!window){
        std::cout << "ERROR:Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glClearColor(0.3, 0.3, 0.3, 1.0);

    while(!glfwWindowShouldClose(window)){
        
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}