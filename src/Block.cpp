#include "Block.h"

using namespace gameModule;

Block::Block(glm::vec2 position, glm::vec2 size, glm::vec3 color, Texture texture) :
    m_texture(texture), m_position(position), m_size(size), m_color(color)
{
    
}

void Block::draw(Renderer& renderer, Shader& shader)
{
    renderer.draw(shader, m_texture,  m_size, m_position, m_color);
}

void Block::changeColor(glm::vec3 changeColor)
{
    m_color = changeColor;
}

void Block::changePosition(glm::vec2 pos)
{
    m_position = pos;
}
