#ifndef POINTLESS_CAMERA_H
#define POINTLESS_CAMERA_H

#include "Common.h"

namespace Pointless
{
	class Camera
	{
	public:
		glm::mat4x4 getViewProjectionMatrix();
	};
}

#endif