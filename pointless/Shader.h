#ifndef POINTLESS_SHADER_H
#define POINTLESS_SHADER_H

#include "Common.h"

namespace Pointless
{
	class Shader;

	class ShaderVariable
	{
	public:
		friend class Shader;

		void setInteger(int value);
		void setMatrix(const glm::mat4x4& value);

	private:
		GLint glHandle;
	};

	class Shader
	{
	public:
        const static int ATTRIB_VERTEX    = 0;
        const static int ATTRIB_TEXCOORD0 = 1;
        const static int ATTRIB_TEXCOORD1 = 2;
        const static int ATTRIB_COLOR     = 3;

		void bind();
        
        static std::shared_ptr<Shader> loadFromFile(const char* vertexShaderFile, const char* fragmentShaderFile);

		ShaderVariable* getUniform(const char* varName);
        
    private:
        GLuint program;
        GLuint vertexShader;
        GLuint fragmentShader;

		std::map<std::string, ShaderVariable*> vars;
        
        static GLuint compileShaderComponent(GLenum type, const char* shaderFile);
	};
}

#endif