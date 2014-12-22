uniform sampler2D tex0;
varying vec2 uvVarying;

void main()
{
    vec4 texColor = texture2D(tex0, uvVarying);
	gl_FragColor = texColor;
}