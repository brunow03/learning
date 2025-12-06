#pragma once

#include "Common.hpp"

class Primitive
{
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

public:
	Primitive();
	virtual ~Primitive();

	//Functions
	void set(const Vertex* vertices,
		const unsigned nrOfVertices,
		const GLuint* indices,
		const unsigned nrOfIndices);

	inline Vertex* getVertices();
	inline GLuint* getIndices();
	inline const unsigned getNrOfVertices();
	inline const unsigned getNrOfIndices();
};

class Triangle : public Primitive
{
public:
	Triangle();
};

class Quad : public Primitive
{
public:
	Quad();
};

class Pyramid : public Primitive
{
public:
	Pyramid();
};

class Cube : public Primitive
{
public:
	Cube();
};