#ifndef ENGINE_H
#define ENGINE_H

#include "renderer/renderer.hpp"
#include "renderer/window.hpp"


extern "C" class Engine
{
private: // private data
	Window* _window = nullptr;
	Renderer* _renderer = nullptr;
	int _width, _height;
	const char* _name;

private: //private methods
	void init();
	void mainLoop();
	void cleanup();

public: // public data
public: // public methods
	Engine(int width, int height, const char* name);
	~Engine();

	void run();
};

#endif