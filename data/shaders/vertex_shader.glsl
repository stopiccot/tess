attribute vec4 position;
attribute vec2 uv;

varying vec2 uvVarying;

uniform mat4 MODELVIEW;

void main()
{
	gl_Position = MODELVIEW * position;
	uvVarying = uv;
}