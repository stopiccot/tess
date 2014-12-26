#ifndef POINTLESS_SHADER_H
#define POINTLESS_SHADER_H

#include "Common.h"

namespace Pointless
{
	class Shader
	{
	public:
        const static int ATTRIB_VERTEX    = 0;
        const static int ATTRIB_TEXCOORD0 = 1;
        const static int ATTRIB_TEXCOORD1 = 2;
        const static int ATTRIB_COLOR     = 3;

		void bind();
        
        static std::shared_ptr<Shader> loadFromFile(const char* vertexShaderFile, const char* fragmentShaderFile);

        GLint getUniform(const char* varName);
        
    private:
        GLuint program;
        GLuint vertexShader;
        GLuint fragmentShader;
        
        static GLuint compileShaderComponent(GLenum type, const char* shaderFile);
	};
}

#endif