#include "Camera.h"

using namespace Pointless;

glm::mat4x4 Camera::getViewProjectionMatrix()
{
	float R = 5.0f;
	float angle = SDL_GetTicks() / 1000.0f;
	glm::mat4x4 viewMatrix = glm::lookAt(glm::vec3(R * sin(angle), 0.0f, R * cos(angle)), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4x4 projMatrix = glm::perspective(45.0f, 800.0f / 600.0f, 0.1f, 100.0f);
	glm::mat4x4 m = projMatrix * viewMatrix;
	return m;
}