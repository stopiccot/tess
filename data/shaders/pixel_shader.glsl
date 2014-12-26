#version 400

uniform sampler2D tex0;
in vec2 uvVarying;
out vec4 fragColor;

void main() {
    vec4 texColor = texture(tex0, uvVarying);
	fragColor = texColor;
}