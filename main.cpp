#include "pointless/Shader.h"

void loadData() {
    std::shared_ptr<Pointless::Shader> shader = Pointless::Shader::loadFromFile("data/shaders/vertex_shader.glsl", "data/shaders/pixel_shader.glsl");
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* sdlWindow = SDL_CreateWindow("tess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(sdlWindow);

#ifdef _WIN32
	glewInit();
#endif

	loadData();

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
        
        glClearColor(0.2f, 0.2f, 0.2f, 0.2f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(sdlWindow);
    }

    return 0;
}