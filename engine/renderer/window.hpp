#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>>
#include "renderer.hpp"

extern "C" class Window
{

private:
	GLFWwindow* _window = nullptr;
	Renderer* _renderer = nullptr;
	PFN_vkCreateInstance _pfnCreateInstance = NULL;

public:
	Window();
	~Window();

	void init(int width, int height, const char* name, Renderer* renderer);
	std::vector<const char*> GetVulkanExtensions();
	int loop();

	void destroy();
};

#endif