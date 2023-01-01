
cmake_minimum_required(VERSION 3.25.1)

project(neoskye)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

include_directories(src)
include_directories(lib/include)

add_subdirectory(lib)

add_library(neoskye
    src/neoskye.cpp
    src/gfx/WindowSubsystem.cpp
    src/gfx/GraphicsSubsystem.cpp
    src/gfx/SpriteBatch.cpp
    src/gfx/Sprite.cpp
    lib/glad/glad.c
)

target_link_libraries(neoskye
    glfw ${OPENGL_LIBRARIES}
)
