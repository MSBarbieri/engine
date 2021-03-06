cmake_minimum_required (VERSION 3.10)
set(DLL_ENGINE "engine")
set(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(RENDER_HEADERS 
"engine/engine.hpp"
"engine/renderer/renderer.hpp"
"engine/renderer/window.hpp"
)
set(RENDER_SOURCES 
"engine/engine.cpp"
"engine/renderer/renderer.cpp"
"engine/renderer/window.cpp")

set(DLL_MAJOR_VERSION 0)
set(DLL_MINOR_VERSION 1)
set(DLL_PATCH_VERSION 0)
set(DLL_VERSION "${DLL_MAJOR_VERSION}.${DLL_MINOR_VERSION}.${DLL_PATCH_VERSION}")

set(THIRD_PARTY_DIR "${CURRENT_DIR}/third_party")


add_subdirectory(${THIRD_PARTY_DIR})


add_library(${DLL_ENGINE} STATIC ${RENDER_HEADERS} ${RENDER_SOURCES})

# compiler flags based on compiler type
if(NOT MSVC)
    target_compile_options(${DLL_ENGINE} PUBLIC -fexceptions)
endif()

if(${VKB_VALIDATION_LAYERS})
    target_compile_definitions(${DLL_ENGINE} PUBLIC VKB_VALIDATION_LAYERS)
endif()

target_link_libraries(${DLL_ENGINE}
    glm
    glfw 
    vulkan
    ${Vulkan_LIBRARY}
    imgui
    spdlog)

target_include_directories(${DLL_ENGINE} PRIVATE
    glm
    glfw
    vulkan
    imgui
    spdlog)



set_target_properties(${DLL_ENGINE} PROPERTIES VERSION ${DLL_VERSION})
install(TARGETS ${DLL_ENGINE}
RUNTIME DESTINATION lib
ARCHIVE DESTINATION lib
LIBRARY DESTINATION lib)


target_include_directories(${DLL_ENGINE} PUBLIC ${CURRENT_DIR})
list(APPEND LINKS_LIST ${DLL_ENGINE})
list(APPEND INCLUDES_LIST ${CURRENT_DIR})

message("libs: in engine ${INCLUDES_LIST}")
message("----------------------")
message("links: in engine ${LINKS_LIST}")
