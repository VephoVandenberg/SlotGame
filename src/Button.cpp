#include "Button.h"

using namespace gameModule;

Button::Button(glm::vec2 position, glm::vec2 size, glm::vec3 color) :
    Block(position, size, color), m_isClicked(false)
{
    
}
