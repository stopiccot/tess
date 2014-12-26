#include "pointless/Shader.h"
#include "pointless/Mesh.h"
#include "pointless/Texture.h"

GLuint indexBuffer;
GLuint vertexBufferPosition;
GLuint vertexBufferUv;
GLuint vertexArray;
std::shared_ptr<Pointless::Shader> shader;
std::shared_ptr<Pointless::Texture> texture;

void loadData() {
    shader = Pointless::Shader::loadFromFile("data/shaders/vertex_shader.glsl", "data/shaders/pixel_shader.glsl");
    texture = Pointless::Texture::loadFromFile("data/textures/wall_color_512.png");
    
    Pointless::Mesh mesh;
    
    mesh.vertices = { { -0.5f, 0.5f, 0.0f }, { 0.5f, 0.5f, 0.0f }, { 0.5f, -0.5f, 0.0f }, { -0.5f, -0.5f, 0.0f } };
    mesh.uvs = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    mesh.indicies = { 0, 1, 2, 0, 2, 3 };
    
    glGenBuffers(1, &vertexBufferPosition);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferPosition);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Pointless::vec3) * mesh.vertices.size(), &mesh.vertices[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &vertexBufferUv);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferUv);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Pointless::vec2) * mesh.uvs.size(), &mesh.uvs[0], GL_STATIC_DRAW);
    
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint16_t) * mesh.indicies.size(), &mesh.indicies[0], GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_VERTEX);
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_TEXCOORD0);
    
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferPosition);
    glVertexAttribPointer(Pointless::Shader::ATTRIB_VERTEX,    3, GL_FLOAT, GL_FALSE, sizeof(Pointless::vec3), 0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferUv);
    glVertexAttribPointer(Pointless::Shader::ATTRIB_TEXCOORD0, 2, GL_FLOAT, GL_FALSE, sizeof(Pointless::vec2), 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
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

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->glHandle);
		shader->bind();
        GLint tex0 = shader->getUniform("tex0");
        glUniform1i(tex0, 0);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
        
        SDL_GL_SwapWindow(sdlWindow);
    }

    return 0;
}