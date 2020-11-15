#pragma once
#include <gl.hpp>
#include <vector>

class VAO
{
private:
	GLuint mVao;
	std::vector<GLuint> mBuffers;
public:
	VAO();
	VAO(const VAO&) = delete;
	~VAO();

	void bind();
	void addVertexBufferObject(const std::vector<float>& data);

	void drawTriangle(GLsizei count);
};

