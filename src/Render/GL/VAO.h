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
	void add_vertex_buffer_object(const std::vector<float>& data);

	void draw(GLsizei count);
};

