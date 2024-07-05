# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.8)

# Set project name
project(PixelGameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add source files to this project's executable
add_executable(PixelGameEngine 
    src/Engine.cpp 
    src/Renderer.cpp 
    src/Input.cpp 
    src/Game.cpp
    src/Physics.cpp
    src/Collision.cpp
    main.cpp
)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find SDL2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Link SDL2 and SDL2_image libraries
target_link_libraries(PixelGameEngine ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

# On Windows, copy SDL2.dll and SDL2_image.dll to the output directory
if(WIN32)
    add_custom_command(TARGET PixelGameEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL_PATH}/SDL2.dll"
        $<TARGET_FILE_DIR:PixelGameEngine>
    )
    add_custom_command(TARGET PixelGameEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_IMAGE_DLL_PATH}/SDL2_image.dll"
        $<TARGET_FILE_DIR:PixelGameEngine>
    )
endif()
