#ifndef POINTLESS_SHADER_H
#define POINTLESS_SHADER_H

#include "Common.h"

namespace Pointless
{
	class Shader
	{
	public:
		static Shader* loadFromFile(const wchar_t* vertexShader, const wchar_t* pixelShader);
	};
}

#endif