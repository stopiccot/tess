#ifndef POINTLESS_MESH_H
#define POINTLESS_MESH_H

#include "Common.h"

namespace Pointless
{
	class Mesh
	{
	public:
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<uint16_t> indicies;
        
        void bake();
//	private:
		GLuint indexBuffer;
		GLuint vertexBufferPosition;
		GLuint vertexBufferUv;
		GLuint vertexArray;
	};
}

#endif