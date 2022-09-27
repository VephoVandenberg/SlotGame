#include <iostream>
#include "IdleState.h"

using namespace gameModule;

IdleState::IdleState(std::array<std::deque<Slot>, 4>& slots) :
    State(slots)
{
    
}

bool IdleState::update(float dt) 
{    
    glm::vec3 newColor = {0.0f, 1.0f, 1.0f};

    m_timeToShow += dt;

    if (m_timeToShow > 0.5f)
    {
	if (m_drumToUpdate == 0)
	{
	    m_prevColor = m_slots[m_drumToUpdate][m_slotToUpdate].getColor();
	    m_slots[m_drumToUpdate][m_slotToUpdate].changeColor(newColor);

	    m_drumToUpdate++;
	    m_timeToShow = 0.0f;
	}
	else if (m_drumToUpdate == m_slots.size())
	{
	    m_slots[m_drumToUpdate - 1][m_slotToUpdate].changeColor(m_prevColor);

	    m_drumToUpdate = 0;
	}
        else
	{
	    m_slots[m_drumToUpdate - 1][m_slotToUpdate].changeColor(m_prevColor);
	    m_prevColor = m_slots[m_drumToUpdate][m_slotToUpdate].getColor();
	    m_slots[m_drumToUpdate][m_slotToUpdate].changeColor(newColor);

	    m_drumToUpdate++;
	    m_timeToShow = 0.0f;
	}

    }

    return true;
}

StateType IdleState::getType() const
{
    return StateType::Idle;
}
