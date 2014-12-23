#version 400

uniform sampler2D tex0;
in vec2 uvVarying;
out vec4 fragColor;

void main() {
    vec4 texColor = vec4(1.0, 0.0, 0.0, 1.0);
	fragColor = texColor;
}