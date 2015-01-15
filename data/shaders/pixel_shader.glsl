#version 400

uniform sampler2D colorTexture;
uniform sampler2D normalTexture;

in vec2 uvVarying;
out vec4 fragColor;

void main() {
    vec4 texColor0 = texture(colorTexture, uvVarying);
    vec4 texColor1 = texture(normalTexture, uvVarying);
	fragColor = mix(texColor0, texColor1, 0.9);
}