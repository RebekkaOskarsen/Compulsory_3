#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shaderClass.h"
#include "Camera.h"
#include "Surface.h"
#include "Objects.h"
#include "Character.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void processInput(GLFWwindow* window); 

const unsigned int width = 800;
const unsigned int height = 800;

//GLfloat vertices[] = 
//{
//	// positions         // colors
//	 0.5f,  0.0f, 0.5f,  0.0f, 1.0f, 0.0f, // top right  
//	 0.5f, 0.0f, -0.5f,  0.0f, 1.0f, 0.0f, // bottom right 
//	-0.5f, 0.0f, -0.5f,  0.0f, 1.0f, 0.0f, // bottom left 
//	-0.5f,  0.0f, 0.5f,  0.0f, 1.0f, 0.0f  // top left 
//};
//
//GLuint indices[] = 
//{
//	0, 1, 3, //first triangle
//	1, 2, 3  //second triangle
//};


int main()
{

	glfwInit(); //Initialize GLFW

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw window creation
	GLFWwindow* window = glfwCreateWindow(width, height, "Compulsory 3", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//Initialize GLAD
	gladLoadGL();

	//Set the viewport
	glViewport(0, 0, width, height);

	Shader shaderProgram("default.vert", "default.frag");

	Surface surface1;

	Objects objects1;
	Objects objects2;
	
	Character character1;

	//unsigned int VBO, VAO, EBO;
	//glGenVertexArrays(1, &VAO);
	//glGenBuffers(1, &VBO);
	//glGenBuffers(1, &EBO);

	//glBindVertexArray(VAO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	////position attribute
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);

	////color attribute
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbind the buffer
	//glBindVertexArray(0); //Unbind the vertex array object 
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//(GL_FRONT_AND_BACK, GL_LINE); // Draw in wireframe



	//Camera
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	while (!glfwWindowShouldClose(window)) // Check if the window should close
	{
		processInput(window);

		//Render
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);

		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		//Flat surface
		surface1.DrawSurface();

		//Objects
		objects1.DrawObjects();
		objects2.DrawObjects();

		//Character
		character1.DrawCharacter();


		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);


}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	std::cout << "Window resized with " << width << "Height" << height << std::endl;
}