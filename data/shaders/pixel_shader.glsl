#version 400

uniform sampler2D tex0;
varying vec2 uvVarying;

void main() {
    vec4 texColor = vec4(1.0, 0.0, 0.0, 1.0);
	gl_FragColor = texColor;
}