#ifndef POINTLESS_COMMON_H
#define POINTLESS_COMMON_H

#include <stdint.h>
#include <vector>
#include <memory>

#ifdef _WIN32
	#include <direct.h>
	#define GLEW_BUILD GLEW_STATIC
	#include <GL/glew.h>
	#include <SDL.h>
	#include <SDL_opengl.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
#endif

#endif