#include "Button.h"

using namespace gameModule;

Button::Button(glm::vec2 position, glm::vec2 size, glm::vec3 color, Texture texture) :
    Block(position, size, color, texture), m_isClicked(false)
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
    double blue;
    if (m_isTarget)
    {
        blue = 0.4f;
    }
    else
    {
        blue = 0.0f;
    }
    // r g b
    changeColor(glm::vec3(m_color.x, m_color.y, blue));
}

void Button::click()
{
    m_isClicked = true;
}

void Button::loosen()
{
    m_isClicked = false;
}
