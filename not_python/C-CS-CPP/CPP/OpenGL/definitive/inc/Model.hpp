#pragma once

#include "Common.hpp"
#include "Mesh.hpp"
#include "OBJLoader.hpp"
#include "Texture.hpp"
#include "Primitive.hpp"

class Model
{
private:
	Material * material;
	Texture* overrideTextureDiffuse;
	Texture* overrideTextureSpecular;
	std::vector<Mesh*> meshes;
	glm::vec3 position;

	void updateUniforms();

public:
	Model(
		glm::vec3 position, 
		Material* material,
		Texture* orTexDif,
		Texture* orTexSpec,
		std::vector<Mesh*>& meshes
		);

	//OBJ file loaded model
	Model(
		glm::vec3 position,
		Material* material,
		Texture* orTexDif,
		Texture* orTexSpec,
		const char* objFile
	);

	~Model();

	//Functions
	void rotate(const glm::vec3 rotation);
	void update();
	void render(Shader* shader);

};