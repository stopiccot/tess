project(tess)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_HOME_DIRECTORY}/cmake)
set(CMAKE_FRAMEWORK_PATH "lib/osx")
set(CMAKE_INCLUDE_PATH "lib/windows/SDL2-2.0.3/include")
set(CMAKE_LIBRARY_PATH "lib/windows/SDL2-2.0.3/lib/x64")

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
add_executable(tess main.cpp)

target_link_libraries(tess ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})