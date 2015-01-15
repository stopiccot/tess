#include "pointless/Shader.h"
#include "pointless/Mesh.h"
#include "pointless/Texture.h"
#include "pointless/Camera.h"

std::shared_ptr<Pointless::Shader> shader;
std::shared_ptr<Pointless::Texture> colorTexture;
std::shared_ptr<Pointless::Texture> normalTexture;
std::shared_ptr<Pointless::Mesh> mesh;

void loadData() {
    shader = Pointless::Shader::loadFromFile("../data/shaders/vertex_shader.glsl", "../data/shaders/pixel_shader.glsl");
    colorTexture = Pointless::Texture::loadFromFile("../data/textures/wall_color_512.png");
    normalTexture = Pointless::Texture::loadFromFile("../data/textures/wall_normals_512.png");
    
    mesh = std::make_shared<Pointless::Mesh>();
    
    mesh->vertices = { { -1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, -1.0f, 0.0f }, { -1.0f, -1.0f, 0.0f } };
    mesh->uvs = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    mesh->indicies = { 0, 1, 2, 0, 2, 3 };

    mesh->bake();
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF);
    SDL_Window* sdlWindow = SDL_CreateWindow("tess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GLContext context = SDL_GL_CreateContext(sdlWindow);
    if (!context) {
        printf("SDL ERROR: \"%s\"", SDL_GetError());
    }

#ifdef _WIN32
	glewInit();
#endif

	char buffer[10 * 1024];
#ifdef _WIN32
	printf("CURRENT DIR: \"%s\"\n", _getcwd(buffer, sizeof(buffer)));
#else
    printf("CURRENT DIR: \"%s\"\n", getcwd(buffer, sizeof(buffer)));
#endif

	printf("GL_VERSION %s\n", glGetString(GL_VERSION));
	printf("GL_VENDOR %s\n", glGetString(GL_VENDOR));
	printf("GL_RENDERER %s\n", glGetString(GL_RENDERER));

	loadData();

    Pointless::Camera camera;

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

        glActiveTexture(GL_TEXTURE0 + 0);
        glBindTexture(GL_TEXTURE_2D, colorTexture->glHandle);

        glActiveTexture(GL_TEXTURE0 + 1);
        glBindTexture(GL_TEXTURE_2D, normalTexture->glHandle);
		
		shader->bind();
		
		auto colorTexture = shader->getUniform("colorTexture");
		colorTexture->setInteger(0);

        auto normalTexture = shader->getUniform("normalTexture");
        normalTexture->setInteger(1);

		auto MODELVIEW = shader->getUniform("MODELVIEW");
		MODELVIEW->setMatrix(camera.getViewProjectionMatrix());
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->indexBuffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
        
        SDL_GL_SwapWindow(sdlWindow);
    }

    return 0;
}