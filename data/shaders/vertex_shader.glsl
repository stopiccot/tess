#version 400

attribute vec3 position;
attribute vec2 uv;

varying vec2 uvVarying;

uniform mat4 MODELVIEW;

void main() {
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
	uvVarying = uv;
}