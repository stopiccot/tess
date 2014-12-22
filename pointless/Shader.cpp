#include "Shader.h"
#include <SDL.h>
#include <stdio.h>

using namespace Pointless;

std::vector<uint8_t> loadFileContentsToBuffer(const wchar_t* filename) {
	std::vector<uint8_t> result;

	FILE* file = _wfopen(filename, L"rb");
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

Shader* Shader::loadFromFile(const wchar_t* vertexShaderFile, const wchar_t* pixelShaderFile)
{
	std::vector<uint8_t> vertexShaderSource = loadFileContentsToBuffer(vertexShaderFile);
	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const GLchar* s = (GLchar*)&vertexShaderSource[0];
	glShaderSource(vertexShader, 1, &s, 0);
	glCompileShader(vertexShader);

	GLint logLength = 0;
	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0)
	{
		std::vector<GLchar> log(logLength);
		glGetShaderInfoLog(vertexShader, logLength, &logLength, &log[0]);
		printf("COMPILE LOG \"%s\"", &log[0]);
	}

	return nullptr;
}


/*
GLuint compileShaderPart(const char* fullpath, GLenum type, GLchar** definitions)
{
io::Asset* asset = io::AssetManager::getInstance()->openAsset(fullpath);
if (asset == NULL) {
return 0;
}

char* buffer = new char[asset->size() + 1]; buffer[asset->size()] = 0;
asset->read(buffer, 1, asset->size());
delete asset;

// compile shader
GLuint shader = glCreateShader(type);

GLchar* strings[10];

int n = 0;
while (*definitions != NULL) {
strings[n++] = *definitions;
definitions++;
}
strings[n++] = (GLchar*)buffer;
strings[n] = NULL;

glShaderSource(shader, n, (const GLchar**)&strings, 0);
glCompileShader(shader);

delete [] buffer;

// print any compile log
GLint logLength = 0;
glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
if (logLength > 0)
{
GLchar* log = new GLchar[logLength];
glGetShaderInfoLog(shader, logLength, &logLength, log);
cham_log("%s shader \"%s\" comlie log:", (type == GL_VERTEX_SHADER ? "vertex" : "pixel"), fullpath);
cham_log("%s\n", log);
delete [] log;
} else {
cham_log("No shader compile log");
}

// check if shader compiled successfully
GLint status;
glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
if (status == 0)
{
glDeleteShader(shader);
cham_error("Failed to complie %s shader \"%s\"", (type == GL_VERTEX_SHADER ? "vertex" : "pixel"), fullpath);
return 0;
}

return shader;
}*/