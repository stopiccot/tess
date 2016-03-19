project(tess)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_HOME_DIRECTORY}/cmake)
set(CMAKE_FRAMEWORK_PATH "lib/osx")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(CMAKE_INCLUDE_PATH
		"lib/windows/SDL2-2.0.4/include"
		"lib/windows/SDL2_image-2.0.0/include"
		"lib/windows/glew-1.11.0/include"
	)

	set(CMAKE_LIBRARY_PATH
		"lib/windows/SDL2-2.0.4/lib/x64"
		"lib/windows/SDL2_image-2.0.0/lib/x64"
		"lib/windows/glew-1.11.0/lib/Release/x64"
	)

    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
endif()

# Find all needed pacakges
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Includes
include_directories("lib/common/glm")
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIR})

# Target
add_executable(tess 
	main.cpp
	pointless/Common.h
	pointless/Camera.h pointless/Camera.cpp
	pointless/Mesh.h pointless/Mesh.cpp
	pointless/Texture.h pointless/Texture.cpp
	pointless/Shader.h pointless/Shader.cpp
)

# Libs
target_link_libraries(tess ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})