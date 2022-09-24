#include "Button.h"

using namespace gameModule;

Button::Button(glm::vec2 position, glm::vec2 size, glm::vec3 color) :
    Block(position, size, color), m_isClicked(false)
{
    
}

void Button::checkCursorButtonCollide(const glm::vec2& position)
{
    bool collisionX = position.x > m_position.x && position.x < m_position.x + m_size.x;
    bool collisionY = position.y > m_position.y && position.y < m_position.y + m_size.y;

    m_isTarget = collisionX && collisionY;
    changeColorIfTarget();
}

void Button::changeColorIfTarget()
{
    if (m_isTarget)
    {
	m_color.z = 0.3f;
    }
    else
    {
	m_color.z = 0.0f;
    }
}
