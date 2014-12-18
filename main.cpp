#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* sdlWindow = SDL_CreateWindow("tess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(sdlWindow);

    bool stop = false;
    while (!stop) {
        SDL_PumpEvents();
            
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT: {
                    stop = true;
                    break;
                }
            }
        }
        
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(sdlWindow);
    }

    return 0;
}