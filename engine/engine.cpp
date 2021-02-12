#include "engine.hpp"

Engine::Engine(int width,int height,const char* name)
{
    this->_width = width;
    this->_height = height;
    this->_name = name;
    std::cout << "started the engine object" << std::endl;
}

void Engine::test()
{
    std::cout << "Hello World From engine instance\n";
}
Engine::~Engine()
{

    std::cout << "destroy engine object \n";
}

void Engine::initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    this->_window = glfwCreateWindow(this->_width, this->_height, "Vulkan", nullptr, nullptr);
}
void Engine::mainLoop() {
    while (!glfwWindowShouldClose(this->_window)) {
        glfwPollEvents();
    }
}

void Engine::cleanup() {
    glfwDestroyWindow(this->_window);

    glfwTerminate();
}

void Engine::run() {
    this->initWindow();
    this->mainLoop();
    this->cleanup();
}