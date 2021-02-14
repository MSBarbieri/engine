#include "window.hpp"


#ifndef ENABLE_VALIDATION_LAYERS
#ifdef NDEBUG
#define ENABLE_VALIDATION_LAYERS 0
#else
#define ENABLE_VALIDATION_LAYERS 1
#endif 
#endif // !ENABLE_VALIDATION_LAYERS

Window::Window() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    if (!glfwVulkanSupported())
    {
        throw std::runtime_error("unable to run with vulkan!");
    }
}

void Window::init(int width,int height,const char* name, Renderer* renderer) {
    _renderer = renderer;
    _window = glfwCreateWindow(width, height, name, nullptr, nullptr);

    _pfnCreateInstance = (PFN_vkCreateInstance)
        glfwGetInstanceProcAddress(_renderer->instance, "vkCreateInstance");
    
    
    _renderer->setSurfaceHandler(glfwGetWin32Window(_window));
    VkResult err = glfwCreateWindowSurface(renderer->instance, _window, NULL, &renderer->surface);
    if(err != VK_SUCCESS) {
        throw std::runtime_error("glfw incapable of liinik vk_surface to window");
    }
}

int Window::loop() {
    if(!glfwWindowShouldClose(this->_window)) {
        glfwPollEvents();
        return 0;
    }
    return -1;
}

void Window::destroy() {
    glfwDestroyWindow(_window);

    glfwTerminate();
}

std::vector<const char*> Window::GetVulkanExtensions() {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (ENABLE_VALIDATION_LAYERS) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}

Window::~Window() {
    destroy();
}