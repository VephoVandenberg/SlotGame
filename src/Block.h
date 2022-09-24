#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "Renderer.h"

namespace gameModule
{
    class Block
    {
    public:
	Block() = default;
	~Block() = default;
	Block& operator=(const Block& button) = default;

	Block(glm::vec2 position, glm::vec2 size, glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f));

	void draw(Renderer& renderer, Shader& shader) const;

	Block(const Block& block) = delete;
	
    protected:
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec3 m_color;
    };
}
