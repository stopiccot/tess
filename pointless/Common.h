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
    #include <OpenGL/gl3.h>
	#include <unistd.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_opengl.h>
#endif

namespace Pointless {
    struct vec2 {
        float u;
        float v;
        
        vec2(float u, float v) : u(u), v(v) {}
    };
    
    struct vec3 {
        float x;
        float y;
        float z;
        
        vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    };
}

#endif