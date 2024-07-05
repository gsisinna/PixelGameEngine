# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.8)

# Set project name
project(PixelGameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/SDL2/include)

# Add source files to this project's executable
add_executable(PixelGameEngine 
    src/Engine.cpp 
    src/Renderer.cpp 
    src/Input.cpp 
    src/Game.cpp 
    main.cpp
)

# Target include directories
target_include_directories(PixelGameEngine PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/SDL2/include)

# Link SDL2 libraries
if(WIN32)
    # On Windows, link with the prebuilt SDL2 libraries
    target_link_libraries(PixelGameEngine 
        ${CMAKE_SOURCE_DIR}/include/SDL2/lib/x64/SDL2.lib 
        ${CMAKE_SOURCE_DIR}/include/SDL2/lib/x64/SDL2main.lib
    )

    # Copy SDL2.dll to the output directory
    add_custom_command(TARGET PixelGameEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/include/SDL2/lib/x64/SDL2.dll"
        $<TARGET_FILE_DIR:PixelGameEngine>
    )
else()
    # On non-Windows platforms, find and link SDL2 dynamically
    find_package(SDL2 REQUIRED)
    target_include_directories(PixelGameEngine PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(PixelGameEngine ${SDL2_LIBRARIES})
endif()
