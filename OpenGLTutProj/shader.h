#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);	// Intention is to write actual shader program in separate files.
											// This class is just used to load shaders in to be built for the GPU, and then sent to GPU

	void Bind();	// Set GPU s.t. it uses the vertex and fragment shader that are part of the particular shader class

	virtual ~Shader();

protected:
private:
	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}
	static const unsigned int NUM_SHADERS = 2;		// One for vertex and other for fragment. There's also a geometry shader which we won't use here.

	GLuint m_program;		// OpenGL's way of keeping track of where program is, and referring to a particular shader (it's a handle)
	GLuint m_shaders[NUM_SHADERS];	
};

#endif