project(tess)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_HOME_DIRECTORY}/cmake)
set(CMAKE_FRAMEWORK_PATH "lib/osx")

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(CMAKE_INCLUDE_PATH
		"lib/windows/SDL2-2.0.3/include"
		"lib/windows/SDL2_image-2.0.0/include"
		"lib/windows/glew-1.11.0/include"
	)

	set(CMAKE_LIBRARY_PATH
		"lib/windows/SDL2-2.0.3/lib/x64"
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

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	find_package(GLEW REQUIRED)
endif()

# Includes
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	include_directories(${GLEW_INCLUDE_DIR})
endif()	

# Target
add_executable(tess 
	main.cpp
	pointless/Common.h
	pointless/Mesh.h
	pointless/Texture.h pointless/Texture.cpp
	pointless/Shader.h pointless/Shader.cpp
)

# Libs
target_link_libraries(tess ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${OPENGL_LIBRARIES})

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	target_link_libraries(tess ${GLEW_LIBRARY})
endif()