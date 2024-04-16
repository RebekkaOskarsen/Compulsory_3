#ifndef CHARACTER_H
#define CHARACTER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class Character
{
	public:
		Character();
		~Character();

		void DrawCharacter();

	private:
		GLuint VAO, VBO, EBO;

};
#endif // !CHARACTER_H
