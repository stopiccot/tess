#ifndef POINTLESS_SHADER_H
#define POINTLESS_SHADER_H

#include "Common.h"

namespace Pointless
{
	class Shader
	{
	public:
        static std::shared_ptr<Shader> loadFromFile(const char* vertexShaderFile, const char* fragmentShaderFile);
    private:
        GLuint program;
        GLuint vertexShader;
        GLuint fragmentShader;
        
        static GLuint compileShaderComponent(GLenum type, const char* shaderFile);
	};
}

#endif