#include "engine.hpp"

Engine::Engine(int width,int height,const char* name)
{
    this->_width = width;
    this->_height = height;
    this->_name = name;
    std::cout << "started the engine object" << std::endl;
    _window = new Window();
    auto extensions = _window->GetVulkanExtensions();
    _renderer = new Renderer(extensions);
}

void Engine::init() {
    _window->init(_width, _height, _name, _renderer);
    _renderer->init(_width,_height);
}
void Engine::mainLoop() {
    while (_window->loop() > -1) {

    }
}


void Engine::run() {
    this->init();
    this->mainLoop();
}

void Engine::cleanup() {
    this->_window->destroy();
    this->_renderer->cleanup();
}

Engine::~Engine()
{
    cleanup();
    std::cout << "destroy engine object \n";
}
