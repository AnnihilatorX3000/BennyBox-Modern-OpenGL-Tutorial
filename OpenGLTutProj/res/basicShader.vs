#version 120

attribute vec3 position;

void main()
{
	// Takes in a position and spits it back out
	gl_Position = vec4(position, 1.0);
}