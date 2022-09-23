#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer.h"

using namespace gameModule;

Renderer::Renderer()
{
    init();
}

void Renderer::draw(Shader& shader, glm::vec2 size, glm::vec2 pos, glm::vec3 color)
{
    shader.use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(pos, 0.0f));
    model = glm::scale(model, glm::vec3(size, 1.0f));

    shader.setUniform4m("model", model);
    shader.setUniform3v("color", color);

    glBindVertexArray(m_quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void Renderer::init()
{
    float verticies[] = {
	0.0f, 0.0f,
	1.0f, 0.0f,
	0.0f, 1.0f,

	0.0f, 1.0f,
	1.0f, 0.0f,
	1.0f, 1.0f
    };

    unsigned int VBO;
    glGenVertexArrays(1, &m_quadVAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(m_quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
