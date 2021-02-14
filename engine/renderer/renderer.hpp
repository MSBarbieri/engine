#ifndef ENGINE_RENDERER_H
#define ENGINE_RENDERER_H

#include <vulkan/vulkan.hpp>
#include <iostream>
#include <algorithm>
#include <optional>
#include <vector>
#include <set>
#include <string>


extern "C" struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

extern "C" struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};


extern "C" class Renderer
{
private: 
	const char* _application_name = __nullptr;
	const char* _engine_name = __nullptr;
	const std::vector<const char*> _validationLayers = {
	"VK_LAYER_KHRONOS_validation"
	};
	const std::vector<const char*> _deviceExtensions = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
	std::vector<VkImageView> swapChainImageViews;

public:
	VkInstance instance = NULL;
	VkDebugUtilsMessengerEXT debugMessenger = NULL;
	VkPhysicalDevice physicalDevice = NULL;
	VkDevice device = NULL;
	VkQueue graphicsQueue = VK_NULL_HANDLE;
	VkQueue presentQueue = VK_NULL_HANDLE;
	VkWin32SurfaceCreateInfoKHR surfaceInfo;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

private:
	static VKAPI_ATTR VkBool32 VKAPI_CALL  debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	VkResult CreateDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice _device);
	bool isDeviceSuitable(VkPhysicalDevice _device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice _device);
	bool checkValidationLayerSupport();
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice _device);
	

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, int width, int height);
public:
	Renderer(std::vector<const char*> extensions);
	~Renderer();

	void createInstance(std::vector<const char*> extensions);
	void setupDebugMessenger();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void createSurface();
	void setSurfaceHandler(HWND handler);
	void pickPhysicalDevice();
	void createLogicalDevice();
	void createSwapChain(int width,int heigth);
	void createImageViews();
	void init(int width,int heigth);
	void cleanup();
};

#endif
