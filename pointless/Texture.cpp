#include "Texture.h"

using namespace Pointless;

std::shared_ptr<Texture> Texture::loadFromFile(const char* filename) {
	std::shared_ptr<Texture> result = std::make_shared<Texture>();
    
    SDL_Surface* surface = IMG_Load(filename);
    
    glGenTextures(1, &result->glHandle);
    glActiveTexture(GL_TEXTURE0 + 0);
    glBindTexture(GL_TEXTURE_2D, result->glHandle);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	
	if (surface->format->format == SDL_PIXELFORMAT_RGBA8888) {
        printf("SDL_PIXELFORMAT_RGBA8888");
    }
    if (surface->format->format == SDL_PIXELFORMAT_RGB24) {
        printf("SDL_PIXELFORMAT_RGB24");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, surface->w, surface->h, 0, GL_RGB, GL_UNSIGNED_BYTE, surface->pixels);
    }
    if (surface->format->format == SDL_PIXELFORMAT_BGR24) {
        printf("SDL_PIXELFORMAT_BGR24");
    }
    if (surface->format->format == SDL_PIXELFORMAT_RGB888) {
        printf("SDL_PIXELFORMAT_RGB888");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, surface->pixels);
    }
    if (surface->format->format == SDL_PIXELFORMAT_BGRX8888) {
        printf("SDL_PIXELFORMAT_BGRX8888");
    }
    if (surface->format->format == SDL_PIXELFORMAT_ARGB8888) {
        printf("SDL_PIXELFORMAT_ARGB8888");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
    }
    if (surface->format->format == SDL_PIXELFORMAT_RGBA8888) {
        printf("SDL_PIXELFORMAT_RGBA8888");
    }
    if (surface->format->format == SDL_PIXELFORMAT_ABGR8888) {
        printf("SDL_PIXELFORMAT_ABGR8888");
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
    }
    if (surface->format->format == SDL_PIXELFORMAT_BGRA8888) {
        printf("SDL_PIXELFORMAT_BGRA8888");
    }

	return result;
}