#pragma once

#include "Common.hpp"

class Texture {
private:
	GLuint id;
	int height, width;
	unsigned int type;
	GLint textureUnit;
public:
	Texture(const char* fileName, GLenum type, GLint texture_unit);
	~Texture();

	inline GLuint getID() const;

	void bind();
	void unbind();

	inline GLint getTextureUnit() const;

	void loadFromFile(const char* fileName);
};