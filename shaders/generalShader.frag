#version 330 core

in vec2 outCoords;
out vec4 fragColor;

uniform bool hasTexture;
uniform sampler2D image;
uniform vec3 color;

void main(void)
{
	if (hasTexture)
	{
		fragColor = vec4(color, 1.0f)*texture(image, outCoords);
	}
	else
	{
		fragColor = vec4(color, 1.0f);
	}
}