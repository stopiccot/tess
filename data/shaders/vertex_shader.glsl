#version 400

in vec3 position;
in vec2 uv;

out vec2 uvVarying;

uniform mat4 MODELVIEW;

void main() {
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
	uvVarying = uv;
}