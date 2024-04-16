#include "Surface.h"

Surface::Surface()
{
	VAO = 0;
	VBO = 0;
	EBO = 0;


	GLfloat surfacevertices[] =
	{
		// positions        /	colors		   //
		 1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // top right  
		 1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom right 
		-1.0f, 0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom left 
		-1.0f, 0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // top left 
		 0.0f, 0.0f,  0.0f,  0.0f, 1.0f, 0.0f  // middle
	};

	GLuint surfaceindices[] =
	{
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4,
		0, 1, 2,
		0, 2, 3
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(surfacevertices), surfacevertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(surfaceindices), surfaceindices, GL_STATIC_DRAW);

	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Draw in wireframe
}

Surface::~Surface()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Surface::DrawSurface()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
