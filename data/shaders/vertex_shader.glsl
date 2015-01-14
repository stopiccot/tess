#version 400

in vec4 position;
in vec2 uv;

out vec2 uvVarying;

uniform mat4 MODELVIEW;

void main() {
	gl_Position = MODELVIEW * position;
	uvVarying = uv;
}