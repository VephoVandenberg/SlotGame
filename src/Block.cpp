#include "Block.h"

using namespace gameModule;

Block::Block(glm::vec2 position, glm::vec2 size, glm::vec3 color) :
    m_position(position), m_size(size), m_color(color)
{
    
}

void Block::draw(Renderer& renderer, Shader& shader) const
{
    renderer.draw(shader, m_size, m_position, m_color);
}

