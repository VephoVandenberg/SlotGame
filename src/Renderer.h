#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "Texture.h"

namespace gameModule
{
    class Renderer
    {
    public:
	Renderer();
	~Renderer() = default;
	
	void draw(Shader& shader, Texture& texture, glm::vec2 size, glm::vec2 pos, glm::vec3 color = glm::vec3(0.0f, 1.0f, 0.0f));
	
    private:
	unsigned int m_quadVAO;

    private:
	void init();
    };
}
