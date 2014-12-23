#include "Shader.h"
#include <SDL.h>
#include <stdio.h>

using namespace Pointless;

std::vector<uint8_t> loadFileContentsToBuffer(const char* filename) {
	std::vector<uint8_t> result;

	FILE* file = fopen(filename, "rb");
	if (!file) {
		return result;
	}

	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);

	result.resize(size);
	fread(&result[0], 1, size, file);
	fclose(file);

	return result;
}

GLuint Shader::compileShaderComponent(GLenum type, const char* shaderFile) {
    std::vector<uint8_t> shaderSource = loadFileContentsToBuffer(shaderFile);
    
    GLuint shader = glCreateShader(type);
    const GLchar* source = (GLchar*)&shaderSource[0];
    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    
    // Print compilation log
    GLint logLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0) {
        std::vector<GLchar> log(logLength);
        glGetShaderInfoLog(shader, logLength, &logLength, &log[0]);
        printf("%s shader \"%s\" comlie log:\n", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"), shaderFile);
        printf("%s\n", &log[0]);
    }
    
    // Check for compilation errors
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == 0) {
        glDeleteShader(shader);
        printf("Failed to complie %s shader \"%s\"\n", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"), shaderFile);
        return 0;
    }
    
    return shader;
}

std::shared_ptr<Shader> Shader::loadFromFile(const char* vertexShaderFile, const char* fragmentShaderFile) {
    std::shared_ptr<Shader> result = std::make_shared<Shader>();
    
    result->vertexShader = compileShaderComponent(GL_VERTEX_SHADER, vertexShaderFile);
    result->fragmentShader = compileShaderComponent(GL_FRAGMENT_SHADER, fragmentShaderFile);
    
    result->program = glCreateProgram();
    glAttachShader(result->program, result->vertexShader);
    glAttachShader(result->program, result->fragmentShader);
    
	return result;
}