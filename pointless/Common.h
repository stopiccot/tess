#ifndef POINTLESS_COMMON_H
#define POINTLESS_COMMON_H

#include <stdint.h>
#include <unistd.h>
#include <vector>

#ifdef _WIN32
	#define GLEW_BUILD GLEW_STATIC
	#include <GL/glew.h>
	#include <SDL.h>
	#include <SDL_opengl.h>
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
#endif

#endif