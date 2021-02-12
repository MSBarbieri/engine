#include "engine.hpp"

Engine::Engine()
{
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