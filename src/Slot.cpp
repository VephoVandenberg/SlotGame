#include <iostream>
#include "Slot.h"

using namespace gameModule;

Slot::Slot(SlotType type, glm::vec2 position, glm::vec2 size,  Texture& texture, glm::vec3 color) :
    Block(position, size, color, texture)
{
    changeType(type);
}

bool Slot::operator==(Slot& slot) const
{
    return m_type == slot.m_type;
}

void Slot::changeType(SlotType type)
{
    glm::vec3 color;
    m_type = type;
    switch(m_type)
    {
    case SlotType::Blue:
    {
	color = glm::vec3(0.0f, 0.0f, 1.0f);
	m_worth = 15;
	break;
    }
    case SlotType::Purple:
    {
	color = glm::vec3(0.5f, 0.0f, 1.0f);
	m_worth = 35;
	break;
    }
    case SlotType::Gold:
    {
	color = glm::vec3(1.0f, 1.0f, 0.0f);
	m_worth = 50;
	break;
    }
    case SlotType::Red:
    {
	color = glm::vec3(1.0f, 0.0f, 0.0f);
	m_worth = 20;
	break;
    }
    case SlotType::Grey:
    {
	color = glm::vec3(0.5f, 0.5f, 0.5f);
	m_worth = 5;
	break;
    }
    case SlotType::Pink:
    {
	color = glm::vec3(1.0f, 0.0f, 1.0f);
	m_worth = 10;
	break;
    }
    }

    changeColor(color);
}
