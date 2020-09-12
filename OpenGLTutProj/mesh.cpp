#include "mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	m_drawCount = numVertices;

	glGenVertexArrays(1, &m_vertexArrayObject);		// Create space for vertexArrayObject
	glBindVertexArray(m_vertexArrayObject);		// Binding makes it such that any operation that affects a vertex object will
												// affect this particular vertex object
	
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);	// Gives us bunches of different blocks of data on GPU for all buffers we want to generate
														// (In this case though, it's just one buffer we're generating)
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);	// Sim as before	
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);	// Takes some data and puts it in the buffer on the GPU

	// Tells OpenGL how to interpret the given data
	glEnableVertexAttribArray(0);	// Tells OpenGL that we're going to tell it how to read one of our attributes as an array
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);	// Tells OpenGL how to actually read that as an array (3 floats - pos attrib)

	glBindVertexArray(0);
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw()
{
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

	glBindVertexArray(0);
}