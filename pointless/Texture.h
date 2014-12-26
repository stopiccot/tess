#ifndef POINTLESS_TEXTURE_H
#define POINTLESS_TEXTURE_H

#include "Common.h"

namespace Pointless
{
	class Texture
	{
	public:
		static std::shared_ptr<Texture> loadFromFile(const char* filename);
//	private:
        GLuint glHandle;
	};
}

#endif