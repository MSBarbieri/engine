#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <GLFW/glfw3.h>

extern "C" class Engine
{
private: // private data
	GLFWwindow* _window = nullptr;
	int _width, _height;
	const char* _name;
private: //private methods
	void initWindow();
	void mainLoop();
	void cleanup();

public: // public data
public: // public methods
	void test();
	Engine(int width, int height, const char* name);
	~Engine();

	void run();
};

#endif