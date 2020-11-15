#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &mVao);
	bind();
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &mVao);
}

void VAO::bind()
{
	glBindVertexArray(mVao);
}

void VAO::addVertexBufferObject(const std::vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(mBuffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	mBuffers.push_back(vbo);
}

void VAO::drawTriangle(GLsizei count)
{
	bind();

	for (size_t i = 0; i < mBuffers.size(); ++i)
	{
		glEnableVertexAttribArray(i);
	}

	glDrawArrays(GL_TRIANGLES, 0, count);

	for (size_t i = 0; i < mBuffers.size(); ++i)
	{
		glDisableVertexAttribArray(i);
	}
}
