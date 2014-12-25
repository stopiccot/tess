#include "pointless/Shader.h"

struct vec2 {
    float u;
    float v;
    
    vec2() : u(0.0f), v(0.0f) {}
    vec2(float u, float v) : u(u), v(v) {}
};

struct vec3 {
    float x;
    float y;
    float z;
    
    vec3() : x(0.0f), y(0.0f), z(0.0f) {}
    vec3(float x, float y, float z) : x(x), y(y), z(z) {}
};

struct Vertex {
    vec3 position;
    vec2 uv;
    
    Vertex() : position(0.0f, 0.0f, 0.0f), uv(0.0f, 0.0f) {}
    Vertex(const vec3& position, const vec2& uv) : position(position), uv(uv) {}
};

GLuint vertexBuffer;
std::shared_ptr<Pointless::Shader> shader;

void loadData() {
    shader = Pointless::Shader::loadFromFile("data/shaders/vertex_shader.glsl", "data/shaders/pixel_shader.glsl");
    
    std::vector<Vertex> vertices;
    
    vertices.push_back(Vertex(vec3(-0.5f,  0.5f, 0.0f), vec2(0.0f, 0.0f)));
    vertices.push_back(Vertex(vec3( 0.5f,  0.5f, 0.0f), vec2(1.0f, 0.0f)));
    vertices.push_back(Vertex(vec3( 0.5f, -0.5f, 0.0f), vec2(1.0f, 1.0f)));

    vertices.push_back(Vertex(vec3(-0.5f,  0.5f, 0.0f), vec2(0.0f, 0.0f)));
    vertices.push_back(Vertex(vec3( 0.5f, -0.5f, 0.0f), vec2(1.0f, 1.0f)));
    vertices.push_back(Vertex(vec3(-0.5f, -0.5f, 0.0f), vec2(0.0f, 1.0f)));
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_VERTEX);
    glEnableVertexAttribArray(Pointless::Shader::ATTRIB_TEXCOORD0);
    
    glVertexAttribPointer(Pointless::Shader::ATTRIB_VERTEX,    3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (uint8_t*)NULL + offsetof(Vertex, position));
    glVertexAttribPointer(Pointless::Shader::ATTRIB_TEXCOORD0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (uint8_t*)NULL + offsetof(Vertex, uv));
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
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

		shader->bind();
        
        glDrawArrays(GL_TRIANGLES, 0, 6);
        
        SDL_GL_SwapWindow(sdlWindow);
    }

    return 0;
}