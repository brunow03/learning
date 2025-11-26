#pragma once

#include "Common.hpp"

class Light
{
protected:
	float intensity;
	glm::vec3 color;

public:
	Light(float intensity, glm::vec3 color);
	~Light();

	//Functions
	virtual void sendToShader(Shader& program);
};

class PointLight : public Light
{
protected:
	glm::vec3 position;
	float constant;
	float linear;
	float quadratic;

public:
	PointLight(glm::vec3 position, float intensity = 1.f, glm::vec3 color = glm::vec3(1.f),
		float constant = 1.f, float linear = 0.045f, float quadratic = 0.0075f)
		: Light(intensity, color);
	~PointLight();

	void setPosition(const glm::vec3 position);
	void sendToShader(Shader& program);
};