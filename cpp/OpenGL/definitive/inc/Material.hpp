#pragma once

#include "Common.hpp"
#include "Primitive.hpp"

class Material
{
private:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	GLint diffuseTex;
	GLint specularTex;

public:
	Material(
			glm::vec3 ambient, 
			glm::vec3 diffuse,
			glm::vec3 specular, 
			GLint diffuseTex,
			GLint specularTex
		);

	~Material();

	//Function
	void sendToShader(Shader& program);
};