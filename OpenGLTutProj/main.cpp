#include "display.h"
#include "shader.h"
#include "mesh.h"
#include <iostream>
#include <GL/glew.h>

int main(int argc, char* argv[])
{
	Display display(800, 600, "Hello W0rl");
	Shader shader("./res/basicShader");
	Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0)),
						  Vertex(glm::vec3(0,0.5,0)), 	
						  Vertex(glm::vec3(0.5,-0.5,0)) };	// Note: OpenGL coords are from -1 to 1 (left/bottom to right/top for x/y)
	Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));

	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		shader.Bind();
		mesh.Draw();

		display.Update();
	}

	return 0;
}