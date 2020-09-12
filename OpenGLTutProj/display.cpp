#include "display.h"
#include <GL/glew.h>
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING); 

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);	//Set 2^8 = 256 different shades of red (Caution: SDL gives you AT LEAST 8 bits)
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);	
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);	// In total, we have 32 bits of colour data	
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);	// Number of bits SDL allocates for each pixel
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);	// Makes SDL allocate space for two windows you can draw on
													//	Only one will be displayed though

	// Create window and create GLContext for GPU to draw directly to window
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(m_window);

	// Gives us access to OpenGL code and functions
	GLenum status = glewInit();	// For searching through OS for OpenGL functions
	if (status != GLEW_OK)
	{
		std::cerr << "GLEW failed to initialise" << std::endl;
	}
	m_isClosed = false;
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);	
	SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);	// Clear colour buffer (i.e. fill screen with the above clear colour)
}

bool Display::IsClosed()
{
	return m_isClosed;
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_window);

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			m_isClosed = true;
	}
}