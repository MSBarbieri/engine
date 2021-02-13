#ifndef RENDERER_H
#define RENDERER_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

extern "C" class Renderer
{
private: 
	const char* _application_name;
	const char* _engine_name;
public:
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;

	VkQueue graphicsQueue;

public:
	Renderer();
	~Renderer();

	static Renderer* Default();

	void createInstance();
	void cleanup();
};

#endif