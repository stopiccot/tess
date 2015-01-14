#ifndef POINTLESS_COMMON_H
#define POINTLESS_COMMON_H

#include <stdint.h>
#include <vector>
#include <memory>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#ifdef _WIN32
	#include <direct.h>
	#define GLEW_BUILD GLEW_STATIC
	#include <GL/glew.h>
	#include <SDL.h>
	#include <SDL_opengl.h>
    #include <SDL_image.h>
#else
    #include <OpenGL/gl3.h>
	#include <unistd.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
    #include <SDL2_image/SDL_image.h>
#endif

#endif