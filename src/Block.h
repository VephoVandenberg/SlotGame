#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Renderer.h"

namespace gameModule
{
    class Block
    {
    public:
	Block() = default;
	~Block() = default;
	Block(const Block& block) = default;
	Block& operator=(const Block& block) = default;

	Block(glm::vec2 position, glm::vec2 size,  glm::vec3 color = glm::vec3(0.0f, 0.0f, 0.0f), Texture texture = Texture());

	virtual void draw(Renderer& renderer, Shader& shader);
	void changeColor(glm::vec3 color);

	inline glm::vec3 getColor() const { return m_color; } 
	
    protected:
	Texture m_texture;
	
	glm::vec2 m_position;
	glm::vec2 m_size;
	glm::vec3 m_color;
    };
}
